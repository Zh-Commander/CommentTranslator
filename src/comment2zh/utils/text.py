from __future__ import annotations

import re
from pathlib import Path

C_CODE_BLOCK_PATTERN = re.compile(r"```c\s*\n?(.*?)```", re.DOTALL | re.IGNORECASE)
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
    if not match:
        return text
    code = match.group(1)
    if text.endswith("\n") and not code.endswith("\n"):
        code += "\n"
    return code


def sanitize_json_text(text: str) -> str:
    return TRAILING_COMMA_PATTERN.sub("", text)


def resolve_path(base_dir: Path, value: str | Path) -> Path:
    path = Path(value)
    if path.is_absolute():
        return path.resolve()
    return (base_dir / path).resolve()
