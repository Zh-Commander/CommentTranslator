import json
import os
import re
import sys
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path
from threading import Lock

try:
    from openai import OpenAI
except ImportError as exc:
    raise SystemExit(
        "Missing dependency: openai. Install it with: pip install openai tqdm"
    ) from exc

try:
    from tqdm import tqdm
except ImportError as exc:
    raise SystemExit(
        "Missing dependency: tqdm. Install it with: pip install openai tqdm"
    ) from exc


SCRIPT_DIR = Path(__file__).resolve().parent
CONFIG_PATH = SCRIPT_DIR / "config.json"
TRAILING_COMMA_PATTERN = re.compile(r",(?=\s*[}\]])")
C_CODE_BLOCK_PATTERN = re.compile(r"```c\s*\n?(.*?)```", re.DOTALL | re.IGNORECASE)


class Translator:
    def __init__(self, config: dict, input_dir: Path | None = None, output_dir: Path | None = None):
        self.config = config
        self.input_dir = input_dir.resolve() if input_dir else (SCRIPT_DIR / config["input_dir"]).resolve()
        self.output_dir = output_dir.resolve() if output_dir else (SCRIPT_DIR / config["output_dir"]).resolve()
        self.system_prompt_path = (SCRIPT_DIR / config["system_prompt_path"]).resolve()
        self.max_workers = int(config.get("max_workers", 4))
        self.extensions = {ext.lower() for ext in config.get("file_extensions", [".c", ".h", ".cpp"])}
        self.request_lock = Lock()

        api_key = os.getenv(config.get("api_key_env", "OPENAI_API_KEY"))
        if not api_key:
            raise SystemExit(
                f"Environment variable {config.get('api_key_env', 'OPENAI_API_KEY')} is not set."
            )

        client_kwargs = {
            "api_key": api_key,
        }

        base_url = config.get("base_url", "").strip()
        if base_url:
            client_kwargs["base_url"] = base_url

        self.client = OpenAI(**client_kwargs)
        self.model = config["model"]
        self.temperature = config.get("temperature", 0)
        self.top_p = config.get("top_p", 1)
        self.timeout = config.get("timeout", 600)
        self.isthink = bool(config.get("isthink", False))

    @staticmethod
    def extract_c_code_block(text: str) -> str:
        match = C_CODE_BLOCK_PATTERN.search(text)
        if not match:
            return text

        code = match.group(1)
        if text.endswith("\n") and not code.endswith("\n"):
            code += "\n"
        return code

    def load_system_prompt(self) -> str:
        if not self.system_prompt_path.is_file():
            raise SystemExit(f"system prompt file not found: {self.system_prompt_path}")
        return self.system_prompt_path.read_text(encoding="utf-8")

    def collect_files(self) -> list[Path]:
        if not self.input_dir.is_dir():
            raise SystemExit(f"input directory not found: {self.input_dir}")

        files = []
        for path in self.input_dir.rglob("*"):
            if path.is_file() and path.suffix.lower() in self.extensions:
                files.append(path)
        files.sort()
        return files

    def build_output_path(self, input_file: Path) -> Path:
        relative_path = input_file.relative_to(self.input_dir)
        return self.output_dir / relative_path

    def translate_file(self, input_file: Path, system_prompt: str) -> tuple[Path, bool, str]:
        user_prompt = input_file.read_text(encoding="utf-8", errors="ignore")

        request_kwargs = {
            "model": self.model,
            "messages": [
                {"role": "system", "content": system_prompt},
                {"role": "user", "content": user_prompt},
            ],
            "temperature": self.temperature,
            "top_p": self.top_p,
            "timeout": self.timeout,
        }

        if self.isthink:
            request_kwargs["extra_body"] = {
                "thinking": {
                    "type": "enabled"
                }
            }

        response = self.client.chat.completions.create(**request_kwargs)

        output_text = response.choices[0].message.content or ""
        output_text = self.extract_c_code_block(output_text)
        output_file = self.build_output_path(input_file)
        output_file.parent.mkdir(parents=True, exist_ok=True)
        output_file.write_text(output_text, encoding="utf-8")
        return input_file, True, ""

    def run(self) -> int:
        system_prompt = self.load_system_prompt()
        files = self.collect_files()

        if not files:
            print(f"No matching files found in: {self.input_dir}")
            return 0

        self.output_dir.mkdir(parents=True, exist_ok=True)

        failures: list[tuple[Path, str]] = []
        with ThreadPoolExecutor(max_workers=self.max_workers, thread_name_prefix="translator") as executor:
            future_map = {
                executor.submit(self.translate_file, input_file, system_prompt): input_file
                for input_file in files
            }

            with tqdm(total=len(files), desc="Translating", unit="file") as progress:
                for future in as_completed(future_map):
                    input_file = future_map[future]
                    try:
                        future.result()
                    except Exception as exc:  # noqa: BLE001
                        failures.append((input_file, str(exc)))
                    finally:
                        progress.update(1)

        if failures:
            print("\nFailed files:")
            for file_path, error in failures:
                print(f"- {file_path}: {error}")
            return 1

        print(f"\nDone. Processed {len(files)} file(s).")
        return 0


def load_config() -> dict:
    if not CONFIG_PATH.is_file():
        raise SystemExit(f"config file not found: {CONFIG_PATH}")

    config_text = CONFIG_PATH.read_text(encoding="utf-8")

    try:
        return json.loads(config_text)
    except json.JSONDecodeError:
        sanitized_text = TRAILING_COMMA_PATTERN.sub("", config_text)
        return json.loads(sanitized_text)


def run_translation(input_dir: Path | None = None, output_dir: Path | None = None, config: dict | None = None) -> int:
    active_config = config or load_config()
    translator = Translator(active_config, input_dir=input_dir, output_dir=output_dir)
    return translator.run()


def main() -> int:
    return run_translation()


if __name__ == "__main__":
    sys.exit(main())
