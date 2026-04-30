from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Any


@dataclass(slots=True)
class OpenAISettings:
    api_key_env: str
    model: str
    base_url: str = ""
    temperature: float = 0.1
    top_p: float = 1.0
    timeout: float = 600.0
    extra_body: dict[str, Any] | None = None


@dataclass(slots=True)
class PathSettings:
    input_dir: Path
    output_dir: Path
    split_dir: Path
    split_output_dir: Path
    system_prompt_path: Path
    log_dir: Path | None = None
    repair_temp_dir: Path | None = None


@dataclass(slots=True)
class ProcessingSettings:
    file_extensions: tuple[str, ...]
    encoding: str
    max_workers: int
    chunk_threshold_bytes: int
    chunk_max_bytes: int
    chunk_min_bytes: int
    fix_backslash_comments: bool = True
    overwrite_output: bool = True
    preserve_input_encoding: bool = False
    retry_count: int = 0
    retry_base_delay_seconds: float = 1.0
    retry_max_delay_seconds: float = 30.0


@dataclass(slots=True)
class PluginSettings:
    check_scripts: tuple[Path, ...]
    repair_scripts: tuple[Path, ...]
    max_translate_attempts: int = 1
    plugin_timeout_seconds: float | None = 60.0


@dataclass(slots=True)
class AppConfig:
    openai: OpenAISettings
    paths: PathSettings
    processing: ProcessingSettings
    plugins: PluginSettings
