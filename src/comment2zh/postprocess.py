from __future__ import annotations

from pathlib import Path


class FixCommentError(Exception):
    pass


def _find_first_block_comment(line: str) -> tuple[int, int] | None:
    in_string: str | None = None
    i = 0
    comment_start: int | None = None

    while i < len(line):
        ch = line[i]
        nxt = line[i + 1] if i + 1 < len(line) else ""

        if in_string is not None:
            if ch == "\\":
                i += 2
                continue
            if ch == in_string:
                in_string = None
            i += 1
            continue

        if ch == '"' or ch == "'":
            in_string = ch
            i += 1
            continue

        if ch == "/" and nxt == "*":
            comment_start = i
            i += 2
            break

        if ch == "/" and nxt == "/":
            return None

        i += 1

    if comment_start is None:
        return None

    while i < len(line):
        ch = line[i]
        nxt = line[i + 1] if i + 1 < len(line) else ""
        if ch == "*" and nxt == "/":
            return comment_start, i + 1
        i += 1

    return None


def _fix_line(line: str) -> tuple[str, bool]:
    comment_range = _find_first_block_comment(line)
    if comment_range is None:
        return line, False

    comment_start, comment_end = comment_range
    prefix_end = comment_start - 1

    while prefix_end >= 0 and line[prefix_end] in " \t":
        prefix_end -= 1

    slash_end = prefix_end
    while prefix_end >= 0 and line[prefix_end] == "\\":
        prefix_end -= 1
    slash_start = prefix_end + 1
    slash_count = slash_end - slash_start + 1

    newline_start = len(line)
    while newline_start > 0 and line[newline_start - 1] in "\r\n":
        newline_start -= 1

    suffix_start = comment_end + 1
    while suffix_start < newline_start and line[suffix_start] in " \t":
        suffix_start += 1

    has_suffix_backslash = suffix_start < newline_start and line[suffix_start] == "\\"

    if slash_count <= 0:
        return line, False

    if has_suffix_backslash:
        fixed_line = line[:slash_start] + line[slash_end + 1 :]
        return fixed_line, True

    fixed_line = line[:slash_start] + line[slash_end + 1 : newline_start] + "\\" + line[newline_start:]
    return fixed_line, True


def fix_file(input_path: Path, encoding: str = "utf-8") -> int:
    try:
        text = input_path.read_text(encoding=encoding)
    except UnicodeDecodeError as exc:
        raise FixCommentError(f"failed to decode file with encoding {encoding}: {exc}") from exc
    except OSError as exc:
        raise FixCommentError(f"failed to read input file: {exc}") from exc

    lines = text.splitlines(keepends=True)
    fixed_count = 0
    fixed_lines: list[str] = []

    for line in lines:
        fixed_line, changed = _fix_line(line)
        fixed_lines.append(fixed_line)
        if changed:
            fixed_count += 1

    if fixed_count == 0:
        return 0

    try:
        input_path.write_text("".join(fixed_lines), encoding=encoding)
    except OSError as exc:
        raise FixCommentError(f"failed to write output file: {exc}") from exc

    return fixed_count


def fix_output_tree(root_dir: Path, extensions: tuple[str, ...], encoding: str) -> int:
    fixed_total = 0
    for file_path in sorted(root_dir.rglob("*")):
        if not file_path.is_file() or file_path.suffix.lower() not in extensions:
            continue
        fixed_total += fix_file(file_path, encoding=encoding)
    return fixed_total
