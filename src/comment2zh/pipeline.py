from __future__ import annotations

import shutil
from pathlib import Path

from .discovery import collect_input_files
from .models import AppConfig
from .prompting import load_system_prompt
from .processor.file_translator import FileTranslator
from .splitter import split_c_file
from .translator.openai_client import OpenAIClient
from .utils.paths import ensure_directory
from .merger import merge_split_output_files
from .plugins import CheckPluginRunner, RepairPluginRunner


class Pipeline:
    def __init__(self, config: AppConfig):
        self.config = config

    def _copy_small_or_split_large(self, files: list[Path]) -> tuple[int, int]:
        split_count = 0
        copied_count = 0
        ensure_directory(self.config.paths.split_dir)
        for source_file in files:
            relative_path = source_file.relative_to(self.config.paths.input_dir)
            target_dir = self.config.paths.split_dir / relative_path.parent
            ensure_directory(target_dir)

            if source_file.stat().st_size < self.config.processing.chunk_threshold_bytes:
                shutil.copy2(source_file, self.config.paths.split_dir / relative_path)
                copied_count += 1
                continue

            log_dir = None
            if self.config.paths.log_dir:
                log_dir = self.config.paths.log_dir / relative_path.parent / source_file.stem
                ensure_directory(log_dir)

            split_c_file(
                source_file,
                target_dir,
                max_size=self.config.processing.chunk_max_bytes,
                min_size=self.config.processing.chunk_min_bytes,
                encoding=self.config.processing.encoding,
                log_dir=log_dir,
            )
            split_count += 1
        return copied_count, split_count

    def _clear_output_dirs(self) -> None:
        if not self.config.processing.overwrite_output:
            return
        for path in (
            self.config.paths.split_dir,
            self.config.paths.split_output_dir,
            self.config.paths.output_dir,
            self.config.paths.repair_temp_dir,
        ):
            if path.exists():
                shutil.rmtree(path)

    def run(self, *, dry_run: bool = False) -> int:
        files = collect_input_files(self.config.paths.input_dir, self.config.processing.file_extensions)
        if not files:
            print(f"No matching files found in: {self.config.paths.input_dir}")
            return 0

        if dry_run:
            split_candidates = sum(1 for file_path in files if file_path.stat().st_size >= self.config.processing.chunk_threshold_bytes)
            print(f"Found {len(files)} file(s). {split_candidates} file(s) will be split.")
            return 0

        self._clear_output_dirs()
        copied_count, split_count = self._copy_small_or_split_large(files)
        print(f"Prepared {len(files)} file(s): copied {copied_count}, split {split_count}.")

        system_prompt = load_system_prompt(self.config.paths.system_prompt_path)
        split_files = collect_input_files(self.config.paths.split_dir, self.config.processing.file_extensions)
        print(f"Translating {len(split_files)} prepared file(s) with {self.config.processing.max_workers} worker(s).")
        client = OpenAIClient(self.config.openai, self.config.processing)
        check_runner = CheckPluginRunner(
            self.config.plugins.check_scripts,
            self.config.plugins.plugin_timeout_seconds,
        )
        translator = FileTranslator(
            self.config,
            client,
            self.config.paths.split_dir,
            self.config.paths.split_output_dir,
            check_runner,
        )
        failures = translator.run(split_files, system_prompt)
        if failures:
            print("\nFailed files:")
            for failure in failures:
                print(f"- {failure.file_path}: {failure.error}")
            return 1

        merged_files = merge_split_output_files(
            self.config.paths.split_output_dir,
            self.config.paths.output_dir,
            encoding=self.config.processing.encoding,
        )
        print(f"Merged or copied {len(merged_files)} output file(s).")

        if self.config.paths.repair_temp_dir is None:
            raise RuntimeError("repair temp directory is not configured")

        repair_runner = RepairPluginRunner(
            self.config.plugins.repair_scripts,
            self.config.paths.repair_temp_dir,
            self.config.plugins.plugin_timeout_seconds,
        )
        repair_result = repair_runner.run(merged_files, self.config.paths.output_dir)
        if repair_result.changed_files:
            print(f"Repaired {repair_result.changed_files} output file(s).")

        return 0
