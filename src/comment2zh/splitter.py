from __future__ import annotations

import argparse
from datetime import datetime
from pathlib import Path


class SplitError(Exception):
    pass


def _line_size(line: str, encoding: str) -> int:
    return len(line.encode(encoding))


def _collect_boundaries(lines: list[str]) -> tuple[list[int], list[int]]:
    empty_boundaries: list[int] = []
    fallback_boundaries: list[int] = []
    in_block_comment = False

    for index, line in enumerate(lines):
        if not in_block_comment:
            fallback_boundaries.append(index)
            if line.strip() == "":
                empty_boundaries.append(index)

        i = 0
        length = len(line)
        in_string: str | None = None

        while i < length:
            ch = line[i]
            nxt = line[i + 1] if i + 1 < length else ""

            if in_string is not None:
                if ch == "\\":
                    i += 2
                    continue
                if ch == in_string:
                    in_string = None
                i += 1
                continue

            if in_block_comment:
                if ch == "*" and nxt == "/":
                    in_block_comment = False
                    i += 2
                    continue
                i += 1
                continue

            if ch == '"' or ch == "'":
                in_string = ch
                i += 1
                continue

            if ch == "/" and nxt == "*":
                in_block_comment = True
                i += 2
                continue

            if ch == "/" and nxt == "/":
                break

            i += 1

    return empty_boundaries, fallback_boundaries


def _build_prefix_sizes(lines: list[str], encoding: str) -> list[int]:
    prefix_sizes = [0]
    total = 0
    for line in lines:
        total += _line_size(line, encoding)
        prefix_sizes.append(total)
    return prefix_sizes


def _range_size(prefix_sizes: list[int], start: int, end: int) -> int:
    return prefix_sizes[end] - prefix_sizes[start]


def _determine_actual_boundaries(
    lines: list[str],
    empty_boundaries: list[int],
    fallback_boundaries: list[int],
    max_size: int,
    min_size: int,
    encoding: str,
) -> list[int]:
    if max_size <= 0:
        raise SplitError("max_size must be greater than 0")
    if min_size < 0:
        raise SplitError("min_size must be greater than or equal to 0")
    if min_size > max_size:
        raise SplitError("min_size cannot be greater than max_size")

    prefix_sizes = _build_prefix_sizes(lines, encoding)
    total_size = prefix_sizes[-1]

    if total_size <= max_size:
        return []

    if not fallback_boundaries:
        raise SplitError("no valid split boundaries found")

    boundaries: list[int] = []
    start = 0
    empty_index = 0
    fallback_index = 0

    while start < len(lines):
        remaining_size = _range_size(prefix_sizes, start, len(lines))
        if remaining_size <= max_size:
            break

        while empty_index < len(empty_boundaries) and empty_boundaries[empty_index] <= start:
            empty_index += 1
        while fallback_index < len(fallback_boundaries) and fallback_boundaries[fallback_index] <= start:
            fallback_index += 1

        best_empty: int | None = None
        scan_empty_index = empty_index
        while scan_empty_index < len(empty_boundaries):
            boundary = empty_boundaries[scan_empty_index]
            if _range_size(prefix_sizes, start, boundary) > max_size:
                break
            best_empty = boundary
            scan_empty_index += 1

        if best_empty is not None:
            boundaries.append(best_empty)
            start = best_empty
            empty_index = scan_empty_index
            continue

        fallback_boundary: int | None = None
        scan_fallback_index = fallback_index
        while scan_fallback_index < len(fallback_boundaries):
            boundary = fallback_boundaries[scan_fallback_index]
            chunk_size = _range_size(prefix_sizes, start, boundary)
            if chunk_size > max_size:
                fallback_boundary = boundary
                break
            scan_fallback_index += 1

        if fallback_boundary is None:
            break

        if fallback_boundary <= start:
            raise SplitError(f"cannot split chunk starting at line {start + 1} within max_size={max_size}")

        boundaries.append(fallback_boundary)
        start = fallback_boundary
        fallback_index = scan_fallback_index

    if boundaries:
        last_start = boundaries[-1]
        last_size = _range_size(prefix_sizes, last_start, len(lines))
        if last_size < min_size:
            boundaries.pop()

    return boundaries


def _build_log_dir(base_dir: Path) -> Path:
    log_root = base_dir / "log"
    timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
    log_dir = log_root / timestamp
    counter = 1
    while log_dir.exists():
        log_dir = log_root / f"{timestamp}_{counter:02d}"
        counter += 1
    log_dir.mkdir(parents=True, exist_ok=False)
    return log_dir


def _write_boundary_reports(
    lines: list[str],
    empty_boundaries: list[int],
    fallback_boundaries: list[int],
    boundaries: list[int],
    output_dir: Path,
    encoding: str,
) -> None:
    prefix_sizes = _build_prefix_sizes(lines, encoding)

    candidate_report = output_dir / "candidate_boundaries.txt"
    fallback_report = output_dir / "fallback_boundaries.txt"
    actual_report = output_dir / "actual_boundaries.txt"

    candidate_lines = [f"{index + 1}\n" for index in empty_boundaries]
    fallback_lines = [f"{index + 1}\n" for index in fallback_boundaries if index > 0]

    actual_lines: list[str] = []
    start = 0
    empty_set = set(empty_boundaries)
    for boundary in boundaries:
        boundary_type = "empty" if boundary in empty_set else "fallback"
        actual_lines.append(
            f"split_before_line={boundary + 1}, chunk_start_line={start + 1}, chunk_end_line={boundary}, chunk_size={_range_size(prefix_sizes, start, boundary)}, boundary_type={boundary_type}\n"
        )
        start = boundary

    actual_lines.append(
        f"final_chunk_start_line={start + 1}, final_chunk_end_line={len(lines)}, chunk_size={_range_size(prefix_sizes, start, len(lines))}\n"
    )

    candidate_report.write_text("".join(candidate_lines), encoding=encoding)
    fallback_report.write_text("".join(fallback_lines), encoding=encoding)
    actual_report.write_text("".join(actual_lines), encoding=encoding)


def _write_chunks(
    lines: list[str],
    boundaries: list[int],
    input_path: Path,
    output_dir: Path,
    encoding: str,
) -> list[Path]:
    output_dir.mkdir(parents=True, exist_ok=True)

    split_points = [0, *boundaries, len(lines)]
    written_files: list[Path] = []

    for index in range(len(split_points) - 1):
        start = split_points[index]
        end = split_points[index + 1]
        chunk_path = output_dir / f"{input_path.stem}.part{index}{input_path.suffix}"
        chunk_path.write_text("".join(lines[start:end]), encoding=encoding)
        written_files.append(chunk_path)

    return written_files


def split_c_file(
    input_path: Path,
    output_dir: str | Path,
    *,
    max_size: int = 10000,
    min_size: int = 5000,
    encoding: str = "utf-8",
    log_dir: Path | None = None,
) -> list[Path]:
    try:
        text = input_path.read_text(encoding=encoding)
    except UnicodeDecodeError as exc:
        raise SplitError(f"failed to decode file with encoding {encoding}: {exc}") from exc
    except OSError as exc:
        raise SplitError(f"failed to read input file: {exc}") from exc

    lines = text.splitlines(keepends=True)
    if not lines:
        raise SplitError("input file is empty")

    empty_boundaries, fallback_boundaries = _collect_boundaries(lines)
    boundaries = _determine_actual_boundaries(
        lines,
        empty_boundaries,
        fallback_boundaries,
        max_size,
        min_size,
        encoding,
    )

    try:
        output_path = Path(output_dir)
        written_files = _write_chunks(lines, boundaries, input_path, output_path, encoding)
        active_log_dir = log_dir or _build_log_dir(input_path.resolve().parent)
        _write_boundary_reports(lines, empty_boundaries, fallback_boundaries, boundaries, active_log_dir, encoding)
        return written_files
    except OSError as exc:
        raise SplitError(f"failed to write output files: {exc}") from exc


def build_arg_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Split a C file into multiple subfiles by safe empty-line boundaries.")
    parser.add_argument("input_file", help="Path to the input C file")
    parser.add_argument("-o", "--output-dir", default="temp/code_split", help="Output directory")
    parser.add_argument("--max-size", type=int, default=10000, help="Maximum size of each chunk in bytes")
    parser.add_argument("--min-size", type=int, default=5000, help="Minimum size of the last chunk in bytes")
    parser.add_argument("--encoding", default="utf-8", help="File encoding. Default: utf-8")
    return parser
