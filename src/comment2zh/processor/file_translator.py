from __future__ import annotations

import sys
from concurrent.futures import ThreadPoolExecutor, as_completed
from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
from threading import Lock
from typing import TextIO

from tqdm import tqdm

from ..config import AppConfig
from ..plugins import CheckPluginRunner
from ..utils.paths import ensure_directory
from ..utils.text import extract_c_code_block
from ..translator.openai_client import OpenAIClient


class TqdmLogWriter:
    def __init__(self, original: TextIO):
        self.original = original
        self._buffer = ""
        self._lock = Lock()

    def write(self, text: str) -> int:
        with self._lock:
            self._buffer += text
            while "\n" in self._buffer:
                line, self._buffer = self._buffer.split("\n", 1)
                if line:
                    tqdm.write(line, file=self.original)
        return len(text)

    def flush(self) -> None:
        with self._lock:
            if self._buffer:
                tqdm.write(self._buffer, file=self.original)
                self._buffer = ""
            self.original.flush()

    def isatty(self) -> bool:
        return self.original.isatty()


@contextmanager
def route_output_above_tqdm():
    original_stdout = sys.stdout
    original_stderr = sys.stderr
    stdout_writer = TqdmLogWriter(original_stdout)
    stderr_writer = TqdmLogWriter(original_stderr)
    sys.stdout = stdout_writer
    sys.stderr = stderr_writer
    try:
        yield
    finally:
        stdout_writer.flush()
        stderr_writer.flush()
        sys.stdout = original_stdout
        sys.stderr = original_stderr



@dataclass(slots=True)
class TranslationFailure:
    file_path: Path
    error: str


class FileTranslator:
    def __init__(
        self,
        config: AppConfig,
        client: OpenAIClient,
        input_dir: Path,
        output_dir: Path,
        check_runner: CheckPluginRunner,
    ):
        self.config = config
        self.client = client
        self.input_dir = input_dir
        self.output_dir = output_dir
        self.check_runner = check_runner

    def build_output_path(self, input_file: Path) -> Path:
        relative_path = input_file.relative_to(self.input_dir)
        return self.output_dir / relative_path

    def translate_file(self, input_file: Path, system_prompt: str) -> None:
        source_text = input_file.read_text(encoding=self.config.processing.encoding)
        output_file = self.build_output_path(input_file)
        ensure_directory(output_file.parent)

        last_check_message = ""
        for attempt in range(1, self.config.plugins.max_translate_attempts + 1):
            translated = self.client.translate(system_prompt=system_prompt, user_prompt=source_text)
            output_text = extract_c_code_block(translated)
            output_file.write_text(output_text, encoding=self.config.processing.encoding)

            check_result = self.check_runner.run(input_file, output_file)
            if check_result.passed:
                return
            last_check_message = check_result.message

        raise RuntimeError(
            f"translation checks failed after {self.config.plugins.max_translate_attempts} attempt(s): "
            f"{last_check_message}"
        )

    def run(self, files: list[Path], system_prompt: str) -> list[TranslationFailure]:
        ensure_directory(self.output_dir)
        failures: list[TranslationFailure] = []
        success_count = 0

        with route_output_above_tqdm():
            with ThreadPoolExecutor(max_workers=self.config.processing.max_workers, thread_name_prefix="translator") as executor:
                future_map = {
                    executor.submit(self.translate_file, file_path, system_prompt): file_path
                    for file_path in files
                }
                with tqdm(total=len(files), desc="Translating", unit="file", dynamic_ncols=True) as progress:
                    for future in as_completed(future_map):
                        file_path = future_map[future]
                        current_name = str(file_path.relative_to(self.input_dir))
                        try:
                            future.result()
                            success_count += 1
                        except Exception as exc:  # noqa: BLE001
                            failures.append(TranslationFailure(file_path=file_path, error=str(exc)))
                        finally:
                            progress.set_postfix_str(
                                f"ok={success_count} fail={len(failures)} current={current_name}"
                            )
                            progress.update(1)

        failures.sort(key=lambda item: str(item.file_path))
        return failures
