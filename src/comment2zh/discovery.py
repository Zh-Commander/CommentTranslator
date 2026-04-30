from __future__ import annotations

from pathlib import Path


def should_process_file(file_path: Path, extensions: tuple[str, ...]) -> bool:
    return file_path.is_file() and file_path.suffix.lower() in extensions


def collect_input_files(input_dir: Path, extensions: tuple[str, ...]) -> list[Path]:
    if not input_dir.is_dir():
        raise FileNotFoundError(f"input directory not found: {input_dir}")

    files = [path for path in input_dir.rglob("*") if should_process_file(path, extensions)]
    files.sort()
    return files
