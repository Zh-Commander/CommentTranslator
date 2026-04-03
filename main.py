import shutil
import sys
from pathlib import Path

from fix_backslash_before_comment import FixCommentError, fix_file
from merge_split_output import run as run_merge
from split_c_file import split_c_file
from translate_comments import load_config, run_translation

SCRIPT_DIR = Path(__file__).resolve().parent
REQUIRED_CONFIG_KEYS = {
    "input_dir",
    "split_dir",
    "split_output_dir",
    "output_dir",
    "Large_file_split_threshold",
    "split_max_token",
    "split_min_token",
    "file_extensions",
    "encoding",  # 可选，如果不加就是可选配置
}



def validate_config(config: dict) -> None:
    missing_keys = sorted(REQUIRED_CONFIG_KEYS - config.keys())
    if missing_keys:
        raise SystemExit(f"Missing config keys: {', '.join(missing_keys)}")


def resolve_dir(path_value: str) -> Path:
    return (SCRIPT_DIR / path_value).resolve()


def should_process_file(file_path: Path, extensions: set[str]) -> bool:
    return file_path.is_file() and file_path.suffix.lower() in extensions


def prepare_directory(path: Path) -> None:
    path.mkdir(parents=True, exist_ok=True)


def collect_input_files(input_dir: Path, extensions: set[str]) -> list[Path]:
    if not input_dir.is_dir():
        raise SystemExit(f"input directory not found: {input_dir}")

    files = [path for path in input_dir.rglob("*") if should_process_file(path, extensions)]
    files.sort()
    return files


def split_inputs(config: dict) -> int:
    input_dir = resolve_dir(config["input_dir"])
    split_dir = resolve_dir(config["split_dir"])
    threshold = int(config["Large_file_split_threshold"])
    max_size = int(config["split_max_token"])
    min_size = int(config["split_min_token"])
    extensions = {ext.lower() for ext in config["file_extensions"]}
    
    # 添加编码配置，默认为 'utf-8'
    encoding = config.get("encoding", "utf-8")  # 从配置读取，默认utf-8

    files = collect_input_files(input_dir, extensions)
    if not files:
        print(f"No matching files found in: {input_dir}")
        return 0

    prepare_directory(split_dir)

    for source_file in files:
        relative_path = source_file.relative_to(input_dir)
        target_dir = split_dir / relative_path.parent
        prepare_directory(target_dir)

        if source_file.stat().st_size < threshold:
            target_file = split_dir / relative_path
            shutil.copy2(source_file, target_file)
            print(f"Copied: {target_file}")
            continue

        # 使用 encoding 参数调用
        split_c_file(
            source_file, 
            target_dir, 
            max_size=max_size, 
            min_size=min_size,
            encoding=encoding
        )

    return 0



def fix_output_files(config: dict) -> int:
    if not config.get("isFixBackSlash", False):
        return 0

    output_dir = resolve_dir(config["output_dir"])
    encoding = config.get("encoding", "utf-8")
    extensions = {ext.lower() for ext in config["file_extensions"]}
    files = collect_input_files(output_dir, extensions)
    fixed_total = 0
    fixed_file_count = 0

    for file_path in files:
        try:
            fixed_lines = fix_file(file_path, encoding=encoding)
        except FixCommentError as exc:
            raise SystemExit(f"Failed to fix backslash comments in {file_path}: {exc}") from exc

        if fixed_lines <= 0:
            continue

        fixed_total += fixed_lines
        fixed_file_count += 1
        print(f"Fixed {fixed_lines} line(s): {file_path}")

    print(f"Fixed {fixed_total} line(s) in {fixed_file_count} file(s).")
    return fixed_total



def main() -> int:
    config = load_config()
    validate_config(config)

    split_inputs(config)
    run_translation(
        input_dir=resolve_dir(config["split_dir"]),
        output_dir=resolve_dir(config["split_output_dir"]),
        config=config,
    )
    run_merge(
        split_output_dir=resolve_dir(config["split_output_dir"]),
        output_dir=resolve_dir(config["output_dir"]),
        config=config,
    )
    fix_output_files(config)
    return 0


if __name__ == "__main__":
    sys.exit(main())
