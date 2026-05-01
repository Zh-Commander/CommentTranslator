from __future__ import annotations

import shutil
from pathlib import Path

from .discovery import collect_input_files
from .models import AppConfig
from .prompting import load_system_prompt
from .processor.file_translator import FileTranslator
from .splitter import split_c_file
from .translator.openai_client import OpenAIClient
from .utils.paths import ensure_directory
from .merger import merge_split_output_files
from .plugins import CheckPluginRunner, NotificationPluginRunner, RepairPluginRunner


class Pipeline:
    def __init__(self, config: AppConfig):
        self.config = config

    def _copy_small_or_split_large(self, files: list[Path]) -> tuple[int, int]:
        split_count = 0
        copied_count = 0
        ensure_directory(self.config.paths.split_dir)
        for source_file in files:
            relative_path = source_file.relative_to(self.config.paths.input_dir)
            target_dir = self.config.paths.split_dir / relative_path.parent
            ensure_directory(target_dir)

            if source_file.stat().st_size < self.config.processing.chunk_threshold_bytes:
                shutil.copy2(source_file, self.config.paths.split_dir / relative_path)
                copied_count += 1
                continue

            log_dir = None
            if self.config.paths.log_dir:
                log_dir = self.config.paths.log_dir / relative_path.parent / source_file.stem
                ensure_directory(log_dir)

            split_c_file(
                source_file,
                target_dir,
                max_size=self.config.processing.chunk_max_bytes,
                min_size=self.config.processing.chunk_min_bytes,
                encoding=self.config.processing.encoding,
                log_dir=log_dir,
            )
            split_count += 1
        return copied_count, split_count

    def _clear_output_dirs(self) -> None:
        if not self.config.processing.overwrite_output:
            return
        for path in (
            self.config.paths.split_dir,
            self.config.paths.split_output_dir,
            self.config.paths.output_dir,
            self.config.paths.repair_temp_dir,
        ):
            if path.exists():
                shutil.rmtree(path)

    def _build_task_info(self, *, dry_run: bool) -> dict:
        return {
            "status": "success",
            "exit_code": 0,
            "dry_run": dry_run,
            "message": "",
            "input_dir": str(self.config.paths.input_dir),
            "output_dir": str(self.config.paths.output_dir),
            "split_dir": str(self.config.paths.split_dir),
            "split_output_dir": str(self.config.paths.split_output_dir),
            "repair_temp_dir": str(self.config.paths.repair_temp_dir) if self.config.paths.repair_temp_dir else None,
            "log_dir": str(self.config.paths.log_dir) if self.config.paths.log_dir else None,
            "file_extensions": list(self.config.processing.file_extensions),
            "encoding": self.config.processing.encoding,
            "max_workers": self.config.processing.max_workers,
            "input_file_count": 0,
            "prepared_file_count": 0,
            "copied_count": 0,
            "split_count": 0,
            "translated_file_count": 0,
            "merged_file_count": 0,
            "repaired_file_count": 0,
            "failed_files": [],
        }

    def _run_notifications(self, task_info: dict) -> None:
        try:
            notify_runner = NotificationPluginRunner(
                self.config.plugins.notify_scripts,
                self.config.plugins.plugin_timeout_seconds,
            )
            result = notify_runner.run(task_info)
        except Exception as exc:  # noqa: BLE001
            print(f"Notification plugin failed: {exc}")
            return

        if not result.passed:
            print(f"Notification plugin failed: {result.message}")

    def _finish(self, exit_code: int, task_info: dict) -> int:
        task_info["exit_code"] = exit_code
        task_info["status"] = "success" if exit_code == 0 else "failed"
        self._run_notifications(task_info)
        return exit_code

    def run(self, *, dry_run: bool = False) -> int:
        task_info = self._build_task_info(dry_run=dry_run)
        files = collect_input_files(self.config.paths.input_dir, self.config.processing.file_extensions)
        task_info["input_file_count"] = len(files)
        if not files:
            message = f"No matching files found in: {self.config.paths.input_dir}"
            print(message)
            task_info["message"] = message
            return self._finish(0, task_info)

        if dry_run:
            split_candidates = sum(1 for file_path in files if file_path.stat().st_size >= self.config.processing.chunk_threshold_bytes)
            message = f"Found {len(files)} file(s). {split_candidates} file(s) will be split."
            print(message)
            task_info["message"] = message
            task_info["copied_count"] = len(files) - split_candidates
            task_info["split_count"] = split_candidates
            return self._finish(0, task_info)

        self._clear_output_dirs()
        copied_count, split_count = self._copy_small_or_split_large(files)
        task_info["copied_count"] = copied_count
        task_info["split_count"] = split_count
        print(f"Prepared {len(files)} file(s): copied {copied_count}, split {split_count}.")

        system_prompt = load_system_prompt(self.config.paths.system_prompt_path)
        split_files = collect_input_files(self.config.paths.split_dir, self.config.processing.file_extensions)
        task_info["prepared_file_count"] = len(split_files)
        print(f"Translating {len(split_files)} prepared file(s) with {self.config.processing.max_workers} worker(s).")
        client = OpenAIClient(self.config.openai, self.config.processing)
        check_runner = CheckPluginRunner(
            self.config.plugins.check_scripts,
            self.config.plugins.plugin_timeout_seconds,
        )
        translator = FileTranslator(
            self.config,
            client,
            self.config.paths.split_dir,
            self.config.paths.split_output_dir,
            check_runner,
        )
        failures = translator.run(split_files, system_prompt)
        task_info["translated_file_count"] = len(split_files) - len(failures)
        if failures:
            print("\nFailed files:")
            for failure in failures:
                print(f"- {failure.file_path}: {failure.error}")
            task_info["failed_files"] = [
                {"file_path": str(failure.file_path), "error": str(failure.error)}
                for failure in failures
            ]
            task_info["message"] = f"Translation failed for {len(failures)} file(s)."
            return self._finish(1, task_info)

        merged_files = merge_split_output_files(
            self.config.paths.split_output_dir,
            self.config.paths.output_dir,
            encoding=self.config.processing.encoding,
        )
        task_info["merged_file_count"] = len(merged_files)
        print(f"Merged or copied {len(merged_files)} output file(s).")

        if self.config.paths.repair_temp_dir is None:
            raise RuntimeError("repair temp directory is not configured")

        repair_runner = RepairPluginRunner(
            self.config.plugins.repair_scripts,
            self.config.paths.repair_temp_dir,
            self.config.plugins.plugin_timeout_seconds,
        )
        repair_result = repair_runner.run(merged_files, self.config.paths.output_dir)
        task_info["repaired_file_count"] = repair_result.changed_files
        if repair_result.changed_files:
            print(f"Repaired {repair_result.changed_files} output file(s).")

        task_info["message"] = "Pipeline completed successfully."
        return self._finish(0, task_info)
