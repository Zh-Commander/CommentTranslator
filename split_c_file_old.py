from __future__ import annotations

import argparse
import re
import sys
from pathlib import Path
from typing import List


class SplitError(Exception):
    pass


class CState:
    def __init__(self) -> None:
        self.in_block_comment = False
        self.in_string = False
        self.in_char = False
        self.escape = False
        self.brace_level = 0
        self.extern_c_level = 0
        self.pp_stack: List[dict[str, bool]] = []
        self.pp_active = True
        self.defined_macros: set[str] = set()
        self.in_pp_continuation = False


def is_extern_c_open_line(line: str) -> bool:
    stripped = line.strip()
    return stripped in {'extern "C" {', 'extern "C"{'}


def is_extern_c_close_line(line: str) -> bool:
    return line.strip() == "}"


def is_macro_defined(name: str, state: CState) -> bool:
    return name in state.defined_macros


def evaluate_pp_condition(expr: str, state: CState) -> bool:
    text = expr.strip()
    if not text:
        return False
    if text == "1":
        return True
    if text == "0":
        return False

    defined_call = re.fullmatch(r"defined\s*\(\s*([A-Za-z_]\w*)\s*\)", text)
    if defined_call:
        return is_macro_defined(defined_call.group(1), state)

    defined_word = re.fullmatch(r"defined\s+([A-Za-z_]\w*)", text)
    if defined_word:
        return is_macro_defined(defined_word.group(1), state)

    not_defined_call = re.fullmatch(r"!\s*defined\s*\(\s*([A-Za-z_]\w*)\s*\)", text)
    if not_defined_call:
        return not is_macro_defined(not_defined_call.group(1), state)

    not_defined_word = re.fullmatch(r"!\s*defined\s+([A-Za-z_]\w*)", text)
    if not_defined_word:
        return not is_macro_defined(not_defined_word.group(1), state)

    return False


def update_preprocessor_state(line: str, state: CState) -> None:
    stripped = line.lstrip()
    if not stripped.startswith("#"):
        return

    directive_line = stripped[1:].strip()
    if not directive_line:
        return

    parts = directive_line.split(None, 1)
    directive = parts[0]
    argument = parts[1] if len(parts) > 1 else ""

    if directive == "if":
        parent_active = state.pp_active
        branch_active = parent_active and evaluate_pp_condition(argument, state)
        state.pp_stack.append({"parent_active": parent_active, "any_taken": branch_active, "branch_active": branch_active})
        state.pp_active = branch_active
        return

    if directive == "ifdef":
        parent_active = state.pp_active
        branch_active = parent_active and is_macro_defined(argument.strip(), state)
        state.pp_stack.append({"parent_active": parent_active, "any_taken": branch_active, "branch_active": branch_active})
        state.pp_active = branch_active
        return

    if directive == "ifndef":
        parent_active = state.pp_active
        branch_active = parent_active and (not is_macro_defined(argument.strip(), state))
        state.pp_stack.append({"parent_active": parent_active, "any_taken": branch_active, "branch_active": branch_active})
        state.pp_active = branch_active
        return

    if directive == "elif":
        if not state.pp_stack:
            return
        frame = state.pp_stack[-1]
        parent_active = bool(frame["parent_active"])
        if not parent_active or bool(frame["any_taken"]):
            branch_active = False
        else:
            branch_active = evaluate_pp_condition(argument, state)
            frame["any_taken"] = branch_active
        frame["branch_active"] = branch_active
        state.pp_active = branch_active
        return

    if directive == "else":
        if not state.pp_stack:
            return
        frame = state.pp_stack[-1]
        parent_active = bool(frame["parent_active"])
        branch_active = parent_active and (not bool(frame["any_taken"]))
        frame["any_taken"] = True
        frame["branch_active"] = branch_active
        state.pp_active = branch_active
        return

    if directive == "endif":
        if not state.pp_stack:
            return
        frame = state.pp_stack.pop()
        state.pp_active = bool(frame["parent_active"])
        return

    if directive == "define" and state.pp_active:
        macro_parts = argument.split(None, 1)
        if macro_parts:
            name = macro_parts[0].split("(", 1)[0]
            if name:
                state.defined_macros.add(name)
        return

    if directive == "undef" and state.pp_active:
        macro_name = argument.split(None, 1)[0] if argument else ""
        if macro_name:
            state.defined_macros.discard(macro_name)


def update_state_with_line(line: str, state: CState) -> None:
    stripped = line.lstrip()
    if stripped.startswith("#"):
        state.in_pp_continuation = line.rstrip().endswith("\\")
        return

    if state.in_pp_continuation:
        state.in_pp_continuation = line.rstrip().endswith("\\")
        return

    if not state.pp_active:
        return

    ignore_extern_c_open = (
        not state.in_block_comment
        and not state.in_string
        and not state.in_char
        and is_extern_c_open_line(line)
    )
    ignore_extern_c_close = (
        not state.in_block_comment
        and not state.in_string
        and not state.in_char
        and state.brace_level == 0
        and state.extern_c_level > 0
        and is_extern_c_close_line(line)
    )

    i = 0
    while i < len(line):
        ch = line[i]
        nxt = line[i + 1] if i + 1 < len(line) else ""

        if state.in_block_comment:
            if ch == "*" and nxt == "/":
                state.in_block_comment = False
                i += 2
            else:
                i += 1
            continue

        if state.in_string:
            if state.escape:
                state.escape = False
            elif ch == "\\":
                state.escape = True
            elif ch == '"':
                state.in_string = False
            i += 1
            continue

        if state.in_char:
            if state.escape:
                state.escape = False
            elif ch == "\\":
                state.escape = True
            elif ch == "'":
                state.in_char = False
            i += 1
            continue

        if ch == "/" and nxt == "*":
            state.in_block_comment = True
            i += 2
            continue

        if ch == "/" and nxt == "/":
            break

        if ch == '"':
            state.in_string = True
            state.escape = False
            i += 1
            continue

        if ch == "'":
            state.in_char = True
            state.escape = False
            i += 1
            continue

        if ch == "{":
            if ignore_extern_c_open:
                state.extern_c_level += 1
                ignore_extern_c_open = False
            else:
                state.brace_level += 1
        elif ch == "}":
            if ignore_extern_c_close:
                state.extern_c_level -= 1
                ignore_extern_c_close = False
            elif state.brace_level > 0:
                state.brace_level -= 1
            else:
                raise SplitError("Encountered unmatched closing brace while scanning the file.")

        i += 1


def collect_candidate_boundaries(lines: List[str]) -> List[int]:
    state = CState()
    boundaries = [0]

    for index, line in enumerate(lines, start=1):
        update_preprocessor_state(line, state)

        line_is_empty = line.strip() == ""
        line_is_valid_boundary = (
            line_is_empty
            and state.pp_active
            and not state.in_block_comment
            and state.brace_level == 0
            and not state.in_string
            and not state.in_char
        )
        if line_is_valid_boundary:
            boundaries.append(index)

        update_state_with_line(line, state)

    if state.in_block_comment:
        raise SplitError("The file ends inside a block comment.")
    if state.in_string:
        raise SplitError("The file ends inside a string literal.")
    if state.in_char:
        raise SplitError("The file ends inside a character literal.")
    if state.pp_stack:
        raise SplitError("The file ends with unmatched preprocessor conditional directives.")
    if state.brace_level != 0:
        raise SplitError("The file ends with unmatched braces.")

    if boundaries[-1] != len(lines):
        boundaries.append(len(lines))

    return boundaries


def build_line_offsets(lines: List[str], encoding: str) -> List[int]:
    offsets = [0]
    total = 0
    for line in lines:
        total += len(line.encode(encoding))
        offsets.append(total)
    return offsets


def chunk_size(offsets: List[int], start_line: int, end_line: int) -> int:
    return offsets[end_line] - offsets[start_line]


def determine_actual_boundaries(
    candidate_boundaries: List[int],
    offsets: List[int],
    min_size: int,
    max_size: int,
) -> List[int]:
    if min_size < 0 or max_size <= 0:
        raise SplitError("min_size must be >= 0 and max_size must be > 0.")
    if min_size > max_size:
        raise SplitError("min_size cannot be larger than max_size.")

    actual = [candidate_boundaries[0]]
    current_index = 0
    last_index = len(candidate_boundaries) - 1

    while current_index < last_index:
        next_index = current_index + 1
        best_index = None
        first_oversized_index = None

        while next_index <= last_index:
            size = chunk_size(offsets, candidate_boundaries[current_index], candidate_boundaries[next_index])
            if size <= max_size:
                best_index = next_index
                next_index += 1
                continue

            first_oversized_index = next_index
            break

        if best_index is not None:
            chosen_index = best_index
        elif first_oversized_index is not None:
            chosen_index = first_oversized_index
        else:
            raise SplitError("Failed to determine the next split boundary.")

        actual.append(candidate_boundaries[chosen_index])
        current_index = chosen_index

    if len(actual) >= 3:
        last_size = chunk_size(offsets, actual[-2], actual[-1])
        if last_size < min_size:
            actual.pop(-2)

    return actual


def write_chunks(
    lines: List[str],
    boundaries: List[int],
    output_dir: Path,
    source_path: Path,
    encoding: str,
) -> List[Path]:
    output_dir.mkdir(parents=True, exist_ok=True)
    created_files: List[Path] = []
    stem = source_path.stem
    suffix = source_path.suffix or ".c"

    for part_index, (start, end) in enumerate(zip(boundaries, boundaries[1:]), start=1):
        part_path = output_dir / f"{stem}.part{part_index}{suffix}"
        part_path.write_text("".join(lines[start:end]), encoding=encoding)
        created_files.append(part_path)

    return created_files


def split_c_file(
    input_file: Path,
    output_dir: str | Path,
    min_size: int,
    max_size: int,
    encoding: str,
) -> List[Path]:
    output_path = Path(output_dir)
    lines = input_file.read_text(encoding=encoding).splitlines(keepends=True)
    candidate_boundaries = collect_candidate_boundaries(lines)
    offsets = build_line_offsets(lines, encoding)
    actual_boundaries = determine_actual_boundaries(candidate_boundaries, offsets, min_size, max_size)
    return write_chunks(lines, actual_boundaries, output_path, input_file, encoding)


def main() -> int:
    parser = argparse.ArgumentParser(description="Split a C file into multiple subfiles by safe empty-line boundaries.")
    parser.add_argument("input_file", help="Path to the input C file")
    parser.add_argument("-o", "--output-dir", default="temp/code_split", help="Output directory")
    parser.add_argument("--max-size", type=int, default=10000, help="Maximum size of each chunk in bytes")
    parser.add_argument("--min-size", type=int, default=5000, help="Minimum size of the last chunk in bytes")
    parser.add_argument("--encoding", default="utf-8", help="File encoding. Default: utf-8")
    args = parser.parse_args()

    input_path = Path(args.input_file)
    if not input_path.is_file():
        print(f"Error: input file not found: {input_path}")
        return 1

    try:
        split_c_file(input_path, args.output_dir, max_size=args.max_size, min_size=args.min_size, encoding=args.encoding)
    except SplitError as exc:
        print(f"Error: {exc}")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
