#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import json
import re
import shutil
import sys
from collections import defaultdict
from pathlib import Path

SCRIPT_DIR = Path(__file__).resolve().parent
CONFIG_PATH = SCRIPT_DIR / "config.json"
PART_FILE_PATTERN = re.compile(r"^(?P<base>.+)\.part(?P<part>\d+)\.(?P<ext>[^.]+)$")
TRAILING_COMMA_PATTERN = re.compile(r",(?=\s*[}\]])")


def load_config() -> dict:
    if not CONFIG_PATH.is_file():
        raise SystemExit(f"config file not found: {CONFIG_PATH}")

    config_text = CONFIG_PATH.read_text(encoding="utf-8")

    try:
        return json.loads(config_text)
    except json.JSONDecodeError:
        sanitized_text = TRAILING_COMMA_PATTERN.sub("", config_text)
        return json.loads(sanitized_text)


def collect_part_files(split_output_dir: Path) -> tuple[dict[tuple[Path, str], list[tuple[int, Path]]], list[tuple[Path, Path]]]:
    if not split_output_dir.is_dir():
        raise SystemExit(f"split output directory not found: {split_output_dir}")

    grouped_files: dict[tuple[Path, str], list[tuple[int, Path]]] = defaultdict(list)
    passthrough_files: list[tuple[Path, Path]] = []

    for file_path in split_output_dir.rglob("*"):
        if not file_path.is_file():
            continue

        relative_path = file_path.relative_to(split_output_dir)
        match = PART_FILE_PATTERN.match(file_path.name)
        if match:
            merged_name = f"{match.group('base')}.{match.group('ext')}"
            part_number = int(match.group("part"))
            grouped_files[(relative_path.parent, merged_name)].append((part_number, file_path))
            continue

        passthrough_files.append((file_path, relative_path))

    return grouped_files, passthrough_files


def merge_group(output_file: Path, parts: list[tuple[int, Path]]) -> None:
    output_file.parent.mkdir(parents=True, exist_ok=True)

    ordered_parts = sorted(parts, key=lambda item: item[0])
    merged_chunks: list[str] = []
    last_index = len(ordered_parts) - 1

    for index, (_, part_path) in enumerate(ordered_parts):
        part_content = part_path.read_text(encoding="utf-8", errors="ignore")
        merged_chunks.append(part_content)
        if index != last_index and not part_content.endswith(("\n", "\r")):
            merged_chunks.append("\n")

    output_file.write_text("".join(merged_chunks), encoding="utf-8")


def copy_passthrough_file(source_file: Path, output_file: Path) -> None:
    output_file.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source_file, output_file)


def run(split_output_dir: Path | None = None, output_dir: Path | None = None, config: dict | None = None) -> int:
    active_config = config or load_config()
    active_split_output_dir = split_output_dir.resolve() if split_output_dir else (SCRIPT_DIR / active_config["split_output_dir"]).resolve()
    active_output_dir = output_dir.resolve() if output_dir else (SCRIPT_DIR / active_config["output_dir"]).resolve()

    grouped_files, passthrough_files = collect_part_files(active_split_output_dir)
    if not grouped_files and not passthrough_files:
        print(f"No files found in: {active_split_output_dir}")
        return 0

    active_output_dir.mkdir(parents=True, exist_ok=True)

    for relative_parent, merged_name in sorted(grouped_files):
        output_file = active_output_dir / relative_parent / merged_name
        merge_group(output_file, grouped_files[(relative_parent, merged_name)])
        print(f"Merged: {output_file}")

    for source_file, relative_path in sorted(passthrough_files, key=lambda item: str(item[1])):
        output_file = active_output_dir / relative_path
        copy_passthrough_file(source_file, output_file)
        print(f"Copied: {output_file}")

    print(f"Done. Merged {len(grouped_files)} file(s) and copied {len(passthrough_files)} file(s).")
    return 0


def main() -> int:
    return run()


if __name__ == "__main__":
    sys.exit(main())
