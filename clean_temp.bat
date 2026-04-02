@echo off
setlocal

set "BASE_DIR=%~dp0"
set "TEMP_SPLIT=%BASE_DIR%temp\code_split"
set "TEMP_OUTPUT=%BASE_DIR%temp\code_split_output"

call :clear_dir "%TEMP_SPLIT%"
call :clear_dir "%TEMP_OUTPUT%"

echo.
echo 清理完成。
pause
exit /b 0

:clear_dir
if not exist "%~1" (
    echo 跳过：%~1 不存在
    exit /b 0
)

del /f /s /q "%~1\*" >nul 2>nul
for /d %%D in ("%~1\*") do rd /s /q "%%~fD"

echo 已清理：%~1
exit /b 0
