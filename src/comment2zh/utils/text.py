from __future__ import annotations

import re
from pathlib import Path

C_CODE_BLOCK_PATTERN = re.compile(r"```(?:c|cpp|c\+\+)?\s*\n?(.*?)```", re.DOTALL | re.IGNORECASE)
CODE_BLOCK_START_PATTERN = re.compile(r"^\s*```(?:c|cpp|c\+\+)?\s*$", re.IGNORECASE)
CODE_BLOCK_END_PATTERN = re.compile(r"^\s*```\s*$")
TRAILING_COMMA_PATTERN = re.compile(r",(?=\s*[}\]])")


def ensure_suffixes(values: list[str] | tuple[str, ...]) -> tuple[str, ...]:
    normalized = []
    for value in values:
        suffix = value.strip().lower()
        if not suffix:
            continue
        if not suffix.startswith("."):
            suffix = f".{suffix}"
        normalized.append(suffix)
    if not normalized:
        raise ValueError("file_extensions cannot be empty")
    return tuple(dict.fromkeys(normalized))


def extract_c_code_block(text: str) -> str:
    match = C_CODE_BLOCK_PATTERN.search(text)
    if match:
        code = match.group(1)
        if text.endswith("\n") and not code.endswith("\n"):
            code += "\n"
        return code

    lines = text.splitlines(keepends=True)
    if lines and CODE_BLOCK_START_PATTERN.match(lines[0].strip()):
        lines = lines[1:]
    if lines and CODE_BLOCK_END_PATTERN.match(lines[-1].strip()):
        lines = lines[:-1]
    return "".join(lines)


def sanitize_json_text(text: str) -> str:
    return TRAILING_COMMA_PATTERN.sub("", text)


def resolve_path(base_dir: Path, value: str | Path) -> Path:
    path = Path(value)
    if path.is_absolute():
        return path.resolve()
    return (base_dir / path).resolve()
