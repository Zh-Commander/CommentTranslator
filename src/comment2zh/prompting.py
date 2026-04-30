from __future__ import annotations

from pathlib import Path


def load_system_prompt(path: Path) -> str:
    if not path.is_file():
        raise FileNotFoundError(f"system prompt file not found: {path}")
    return path.read_text(encoding="utf-8")
