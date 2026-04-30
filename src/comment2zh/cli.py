from __future__ import annotations

import argparse
from pathlib import Path

from .config import load_config
from .pipeline import Pipeline


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="Translate C/C++ source comments into Chinese with an OpenAI-compatible API.")
    parser.add_argument("run", nargs="?", default="run", help=argparse.SUPPRESS)
    parser.add_argument("--config", default="config.json", help="Path to config file")
    parser.add_argument("--input-dir", help="Override input directory")
    parser.add_argument("--output-dir", help="Override output directory")
    parser.add_argument("--workers", type=int, help="Override max workers")
    parser.add_argument("--extensions", nargs="+", help="Override file extensions")
    parser.add_argument("--skip-fix", action="store_true", help="Skip post-fix for backslash comments")
    parser.add_argument("--dry-run", action="store_true", help="Scan and plan files without calling the model")
    return parser


def main() -> int:
    parser = build_parser()
    args = parser.parse_args()

    config = load_config(args.config)
    if args.input_dir:
        config.paths.input_dir = Path(args.input_dir).resolve()
    if args.output_dir:
        config.paths.output_dir = Path(args.output_dir).resolve()
    if args.workers is not None:
        config.processing.max_workers = max(1, args.workers)
    if args.extensions:
        config.processing.file_extensions = tuple(ext.lower() if ext.startswith(".") else f".{ext.lower()}" for ext in args.extensions)
    if args.skip_fix:
        config.processing.fix_backslash_comments = False

    pipeline = Pipeline(config)
    return pipeline.run(dry_run=args.dry_run)
