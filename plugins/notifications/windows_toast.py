from __future__ import annotations

import os
import platform
import subprocess
import sys


POWERSHELL_SCRIPT = r'''
Add-Type -AssemblyName System.Windows.Forms
Add-Type -AssemblyName System.Drawing

$title = $env:COMMENT2ZH_TOAST_TITLE
$body = $env:COMMENT2ZH_TOAST_BODY

$icon = [System.Drawing.SystemIcons]::Information
if ($env:COMMENT2ZH_TOAST_STATUS -eq "failed") {
    $icon = [System.Drawing.SystemIcons]::Error
}

$notifyIcon = New-Object System.Windows.Forms.NotifyIcon
$notifyIcon.Icon = $icon
$notifyIcon.Text = "Comment2ZH"
$notifyIcon.Visible = $true
$notifyIcon.BalloonTipTitle = $title
$notifyIcon.BalloonTipText = $body
$notifyIcon.BalloonTipIcon = if ($env:COMMENT2ZH_TOAST_STATUS -eq "failed") { "Error" } else { "Info" }
$notifyIcon.ShowBalloonTip(5000)
Start-Sleep -Seconds 6
$notifyIcon.Visible = $false
$notifyIcon.Dispose()
'''


def _build_body(task_info: dict) -> str:
    status = task_info.get("status", "unknown")
    message = task_info.get("message") or "任务已完成"
    exit_code = task_info.get("exit_code", "unknown")
    failed_files = task_info.get("failed_files") or []

    if failed_files:
        return f"{message}\n失败文件数：{len(failed_files)}\n退出码：{exit_code}"
    return f"{message}\n状态：{status}\n退出码：{exit_code}"


def notify(task_info: dict) -> bool:
    if platform.system() != "Windows":
        print("[windows_toast] skipped: current system is not Windows")
        return True

    title = "注释中文化任务完成"
    if task_info.get("status") == "failed":
        title = "注释中文化任务失败"

    env = os.environ.copy()
    env["COMMENT2ZH_TOAST_TITLE"] = title
    env["COMMENT2ZH_TOAST_BODY"] = _build_body(task_info)
    env["COMMENT2ZH_TOAST_STATUS"] = str(task_info.get("status", "unknown"))

    try:
        subprocess.run(
            [
                "powershell",
                "-NoProfile",
                "-ExecutionPolicy",
                "Bypass",
                "-Command",
                POWERSHELL_SCRIPT,
            ],
            check=True,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.PIPE,
            text=True,
            timeout=10,
            env=env,
        )
    except Exception as exc:  # noqa: BLE001
        print(f"[windows_toast] failed: {exc}", file=sys.stderr)
        return False

    return True
