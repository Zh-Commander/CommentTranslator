from __future__ import annotations

import shutil
from pathlib import Path


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


def _display_path(path: Path) -> str:
    try:
        return str(path.resolve().relative_to(Path.cwd().resolve()))
    except ValueError:
        return str(path)


def repair(input_path: str, output_path: str) -> bool:
    source = Path(input_path)
    target = Path(output_path)
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source, target)

    text = target.read_text(encoding="utf-8")
    lines = text.splitlines(keepends=True)
    fixed_count = 0
    fixed_lines: list[str] = []
    for line in lines:
        fixed_line, changed = _fix_line(line)
        fixed_lines.append(fixed_line)
        if changed:
            fixed_count += 1
    target.write_text("".join(fixed_lines), encoding="utf-8")
    if fixed_count > 0:
        print(
            f"[fix_backslash_comments] {_display_path(source)} -> {_display_path(target)}, "
            f"fixed {fixed_count} line(s)"
        )
    return True
