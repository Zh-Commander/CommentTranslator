from __future__ import annotations

import argparse
import sys
from pathlib import Path


class FixCommentError(Exception):
    pass



def _find_block_comment_start(line: str, end_index: int) -> int | None:
    in_string: str | None = None
    i = 0

    while i <= end_index:
        ch = line[i]
        nxt = line[i + 1] if i + 1 <= end_index else ""

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
            return i

        i += 1

    return None



def _find_trailing_block_comment(line: str) -> tuple[int, int] | None:
    end = len(line) - 1
    while end >= 0 and line[end] in " \t\r\n":
        end -= 1

    if end < 1 or line[end - 1] != "*" or line[end] != "/":
        return None

    start = _find_block_comment_start(line, end)
    if start is None:
        return None

    return start, end



def _fix_line(line: str) -> tuple[str, bool]:
    comment_range = _find_trailing_block_comment(line)
    if comment_range is None:
        return line, False

    comment_start, comment_end = comment_range
    prefix_end = comment_start - 1

    while prefix_end >= 0 and line[prefix_end] in " \t":
        prefix_end -= 1

    if prefix_end < 0 or line[prefix_end] != "\\":
        return line, False

    newline_start = len(line)
    while newline_start > 0 and line[newline_start - 1] in "\r\n":
        newline_start -= 1

    fixed_line = (
        line[:prefix_end]
        + line[prefix_end + 1 : newline_start]
        + "\\"
        + line[newline_start:]
    )
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



def main() -> int:
    parser = argparse.ArgumentParser(
        description="Move a trailing backslash from before a trailing block comment to after the comment."
    )
    parser.add_argument("input_file", help="Path to the C source/header file")
    args = parser.parse_args()

    input_path = Path(args.input_file)
    if not input_path.is_file():
        print(f"Error: input file not found: {input_path}")
        return 1

    try:
        fixed_count = fix_file(input_path)
    except FixCommentError as exc:
        print(f"Error: {exc}")
        return 1

    print(f"Fixed {fixed_count} line(s): {input_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
