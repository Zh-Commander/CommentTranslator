from __future__ import annotations

import importlib.util
import shutil
from concurrent.futures import ThreadPoolExecutor, TimeoutError
from dataclasses import dataclass
from pathlib import Path
from types import ModuleType
from typing import Callable

from .utils.paths import ensure_directory


class PluginError(Exception):
    pass


@dataclass(slots=True)
class CheckResult:
    passed: bool
    message: str = ""


@dataclass(slots=True)
class RepairResult:
    changed_files: int = 0


CheckFunction = Callable[[str, str], bool]
RepairFunction = Callable[[str, str], bool]


def _load_module(script_path: Path) -> ModuleType:
    if not script_path.is_file():
        raise PluginError(f"plugin script not found: {script_path}")

    module_name = f"comment2zh_plugin_{abs(hash(script_path))}"
    spec = importlib.util.spec_from_file_location(module_name, script_path)
    if spec is None or spec.loader is None:
        raise PluginError(f"failed to load plugin script: {script_path}")

    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def _get_function(module: ModuleType, names: tuple[str, ...], script_path: Path) -> Callable[..., bool]:
    for name in names:
        value = getattr(module, name, None)
        if callable(value):
            return value
    joined_names = ", ".join(names)
    raise PluginError(f"plugin {script_path} must define one of: {joined_names}")


def _call_with_timeout(function: Callable[..., bool], args: tuple[str, str], timeout_seconds: float | None) -> bool:
    if timeout_seconds is None:
        return function(*args)

    with ThreadPoolExecutor(max_workers=1, thread_name_prefix="plugin") as executor:
        future = executor.submit(function, *args)
        try:
            return future.result(timeout=timeout_seconds)
        except TimeoutError as exc:
            raise PluginError(f"plugin timed out after {timeout_seconds:g} second(s)") from exc


@dataclass(slots=True)
class CheckPlugin:
    script_path: Path
    function: CheckFunction
    timeout_seconds: float | None

    def run(self, before_path: Path, after_path: Path) -> CheckResult:
        try:
            result = _call_with_timeout(
                self.function,
                (str(before_path), str(after_path)),
                self.timeout_seconds,
            )
        except Exception as exc:  # noqa: BLE001
            return CheckResult(False, f"{self.script_path}: {exc}")

        if result is True:
            return CheckResult(True)
        return CheckResult(False, f"{self.script_path}: returned {result!r}")


@dataclass(slots=True)
class RepairPlugin:
    script_path: Path
    function: RepairFunction
    timeout_seconds: float | None

    def run(self, input_path: Path, output_path: Path) -> None:
        try:
            result = _call_with_timeout(
                self.function,
                (str(input_path), str(output_path)),
                self.timeout_seconds,
            )
        except Exception as exc:  # noqa: BLE001
            raise PluginError(f"repair plugin failed: {self.script_path}: {exc}") from exc

        if result is not True:
            raise PluginError(f"repair plugin failed: {self.script_path}: returned {result!r}")


class CheckPluginRunner:
    def __init__(self, script_paths: tuple[Path, ...], timeout_seconds: float | None):
        self.timeout_seconds = timeout_seconds
        self.plugins = tuple(self._load_plugin(path) for path in script_paths)

    def _load_plugin(self, script_path: Path) -> CheckPlugin:
        module = _load_module(script_path)
        function = _get_function(module, ("check", "main"), script_path)
        return CheckPlugin(script_path=script_path, function=function, timeout_seconds=self.timeout_seconds)

    def run(self, before_path: Path, after_path: Path) -> CheckResult:
        for plugin in self.plugins:
            result = plugin.run(before_path, after_path)
            if not result.passed:
                return result
        return CheckResult(True)


class RepairPluginRunner:
    def __init__(
        self,
        script_paths: tuple[Path, ...],
        temp_dir: Path,
        timeout_seconds: float | None,
    ):
        self.temp_dir = temp_dir
        self.timeout_seconds = timeout_seconds
        self.plugins: list[RepairPlugin] = []
        self.plugins.extend(self._load_plugin(path) for path in script_paths)

    def _load_plugin(self, script_path: Path) -> RepairPlugin:
        module = _load_module(script_path)
        function = _get_function(module, ("repair", "main"), script_path)
        return RepairPlugin(script_path=script_path, function=function, timeout_seconds=self.timeout_seconds)

    def run_file(self, file_path: Path, output_root: Path) -> bool:
        if not self.plugins:
            return False

        relative_path = file_path.relative_to(output_root)
        current_input = file_path
        changed = False

        for index, plugin in enumerate(self.plugins, start=1):
            step_output = self.temp_dir / relative_path.parent / f"{file_path.name}.repair{index}{file_path.suffix}"
            plugin.run(current_input, step_output)
            current_input = step_output
            changed = True

        if changed:
            shutil.copy2(current_input, file_path)
        return changed

    def run(self, files: list[Path], output_root: Path) -> RepairResult:
        ensure_directory(self.temp_dir)
        changed_files = 0
        for file_path in files:
            if self.run_file(file_path, output_root):
                changed_files += 1
        return RepairResult(changed_files=changed_files)
