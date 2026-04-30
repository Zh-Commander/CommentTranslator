from __future__ import annotations

import shutil
from collections import defaultdict
from pathlib import Path
import re

PART_FILE_PATTERN = re.compile(r"^(?P<base>.+)\.part(?P<part>\d+)\.(?P<ext>[^.]+)$")


def collect_part_files(split_output_dir: Path) -> tuple[dict[tuple[Path, str], list[tuple[int, Path]]], list[tuple[Path, Path]]]:
    if not split_output_dir.is_dir():
        raise FileNotFoundError(f"split output directory not found: {split_output_dir}")

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


def merge_group(output_file: Path, parts: list[tuple[int, Path]], *, encoding: str) -> None:
    output_file.parent.mkdir(parents=True, exist_ok=True)

    ordered_parts = sorted(parts, key=lambda item: item[0])
    merged_chunks: list[str] = []
    last_index = len(ordered_parts) - 1

    for index, (_, part_path) in enumerate(ordered_parts):
        part_content = part_path.read_text(encoding=encoding)
        merged_chunks.append(part_content)
        if index != last_index and not part_content.endswith(("\n", "\r")):
            merged_chunks.append("\n")

    output_file.write_text("".join(merged_chunks), encoding=encoding)


def copy_passthrough_file(source_file: Path, output_file: Path) -> None:
    output_file.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source_file, output_file)


def merge_split_output_files(split_output_dir: Path, output_dir: Path, *, encoding: str) -> list[Path]:
    grouped_files, passthrough_files = collect_part_files(split_output_dir)
    if not grouped_files and not passthrough_files:
        return []

    output_dir.mkdir(parents=True, exist_ok=True)
    output_files: list[Path] = []

    for relative_parent, merged_name in sorted(grouped_files):
        output_file = output_dir / relative_parent / merged_name
        merge_group(output_file, grouped_files[(relative_parent, merged_name)], encoding=encoding)
        output_files.append(output_file)

    for source_file, relative_path in sorted(passthrough_files, key=lambda item: str(item[1])):
        output_file = output_dir / relative_path
        copy_passthrough_file(source_file, output_file)
        output_files.append(output_file)

    return output_files


def merge_split_output(split_output_dir: Path, output_dir: Path, *, encoding: str) -> int:
    return len(merge_split_output_files(split_output_dir, output_dir, encoding=encoding))
