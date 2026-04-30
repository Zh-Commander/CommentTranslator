from __future__ import annotations

import json
from pathlib import Path
from typing import Any

from .models import AppConfig, OpenAISettings, PathSettings, PluginSettings, ProcessingSettings
from .utils.text import ensure_suffixes, resolve_path, sanitize_json_text

CONFIG_FILE_NAME = "config.json"


class ConfigError(Exception):
    pass


def _read_json_file(path: Path) -> dict[str, Any]:
    if not path.is_file():
        raise ConfigError(f"config file not found: {path}")

    text = path.read_text(encoding="utf-8")
    try:
        data = json.loads(text)
    except json.JSONDecodeError:
        data = json.loads(sanitize_json_text(text))

    if not isinstance(data, dict):
        raise ConfigError("config root must be a JSON object")
    return data


def _get_required(data: dict[str, Any], key: str) -> Any:
    if key not in data:
        raise ConfigError(f"missing config key: {key}")
    return data[key]


def _resolve_path_list(project_root: Path, values: Any, key: str) -> tuple[Path, ...]:
    if values is None:
        return ()
    if not isinstance(values, list):
        raise ConfigError(f"config key {key} must be a list")
    return tuple(resolve_path(project_root, str(value)) for value in values)


def _optional_timeout(value: Any) -> float | None:
    if value is None:
        return None
    timeout = float(value)
    if timeout <= 0:
        return None
    return timeout


def load_config(config_path: str | Path | None = None) -> AppConfig:
    project_root = Path(__file__).resolve().parents[2]
    active_config_path = resolve_path(project_root, config_path or CONFIG_FILE_NAME)
    raw = _read_json_file(active_config_path)

    chunk_threshold = int(raw.get("chunk_threshold_bytes", raw.get("Large_file_split_threshold", 20000)))
    chunk_max = int(raw.get("chunk_max_bytes", raw.get("split_max_token", 20000)))
    chunk_min = int(raw.get("chunk_min_bytes", raw.get("split_min_token", 10000)))
    fix_backslash = bool(raw.get("fix_backslash_comments", raw.get("isFixBackSlash", True)))

    openai = OpenAISettings(
        api_key_env=str(raw.get("api_key_env", "OPENAI_API_KEY")),
        model=str(_get_required(raw, "model")),
        base_url=str(raw.get("base_url", "")).strip(),
        temperature=float(raw.get("temperature", 0.1)),
        top_p=float(raw.get("top_p", 1)),
        timeout=float(raw.get("timeout", 600)),
        extra_body=raw.get("extra_body"),
    )

    paths = PathSettings(
        input_dir=resolve_path(project_root, str(_get_required(raw, "input_dir"))),
        output_dir=resolve_path(project_root, str(_get_required(raw, "output_dir"))),
        split_dir=resolve_path(project_root, str(_get_required(raw, "split_dir"))),
        split_output_dir=resolve_path(project_root, str(_get_required(raw, "split_output_dir"))),
        system_prompt_path=resolve_path(project_root, str(_get_required(raw, "system_prompt_path"))),
        log_dir=resolve_path(project_root, str(raw["log_dir"])) if raw.get("log_dir") else None,
        repair_temp_dir=resolve_path(project_root, str(raw.get("repair_temp_dir", "temp/repair"))),
    )

    processing = ProcessingSettings(
        file_extensions=ensure_suffixes(tuple(raw.get("file_extensions", [".c", ".h", ".cpp"]))),
        encoding=str(raw.get("encoding", "utf-8")),
        max_workers=max(1, int(raw.get("max_workers", 4))),
        chunk_threshold_bytes=chunk_threshold,
        chunk_max_bytes=chunk_max,
        chunk_min_bytes=chunk_min,
        fix_backslash_comments=fix_backslash,
        overwrite_output=bool(raw.get("overwrite_output", True)),
        preserve_input_encoding=bool(raw.get("preserve_input_encoding", False)),
        retry_count=max(0, int(raw.get("retry_count", 0))),
        retry_base_delay_seconds=max(0.0, float(raw.get("retry_base_delay_seconds", 1.0))),
        retry_max_delay_seconds=max(0.0, float(raw.get("retry_max_delay_seconds", 30.0))),
    )

    plugins = PluginSettings(
        check_scripts=_resolve_path_list(project_root, raw.get("check_scripts", []), "check_scripts"),
        repair_scripts=_resolve_path_list(project_root, raw.get("repair_scripts", []), "repair_scripts"),
        max_translate_attempts=max(1, int(raw.get("max_translate_attempts", 1))),
        plugin_timeout_seconds=_optional_timeout(raw.get("plugin_timeout_seconds", 60)),
    )

    return AppConfig(openai=openai, paths=paths, processing=processing, plugins=plugins)
