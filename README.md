# C/C++ 注释自动中文化工具

本项目用于借助 OpenAI 兼容接口，将 C/C++ 源码中的英文注释自动翻译为中文，并在必要位置补充适合初学者理解的中文注释。项目以 CLI 为主入口，核心目标是：流程清晰、模块化、便于维护和扩展。

## 当前处理流程

完整流程如下：

```text
扫描 -> 切分/复制 -> AI 翻译 -> 检查/失败重译 -> 合并 -> 修复插件链
```

各阶段说明：

1. **扫描**
   - 从 `input_dir` 递归扫描指定扩展名文件。
   - 默认处理 `.c`、`.h`、`.cpp`。

2. **切分/复制**
   - 小文件直接复制到 `split_dir`。
   - 大文件按安全边界切分成 `.partN` 文件，避免模型上下文过长。
   - 切分逻辑尽量避开字符串、块注释等危险位置。

3. **AI 翻译**
   - 实际翻译的是 `split_dir` 中的准备后文件。
   - 翻译结果写入 `split_output_dir`。
   - 支持并发翻译和进度条。

4. **检查/失败重译**
   - 每个文件翻译完成后，依次运行 `check_scripts` 中的检查插件。
   - 每个检查插件收到两个参数：翻译前文件路径、翻译后文件路径。
   - 只有所有检查插件都返回 `True`，该文件才算通过。
   - 检查失败时，会按 `max_translate_attempts` 重新调用 AI 翻译该文件。

5. **合并**
   - 将 `.partN` 翻译结果重新合并成原始文件结构。
   - 未切分的小文件直接复制到最终输出目录。

6. **修复插件链**
   - 合并后的每个文件会依次经过 `repair_scripts` 中的修复插件。
   - 每个修复插件读取上一步输出，并写入自己的输出文件。
   - 最后一个修复结果覆盖回 `output_dir` 中的最终文件。

## 目录结构

```text
.
├── main.py                         # 项目根入口，加载 src 后调用 CLI
├── config.json                     # 当前运行配置，通常由用户维护
├── config.example.json             # 配置模板
├── code_input/                     # 默认输入目录
├── code_output/                    # 默认最终输出目录
├── temp/
│   ├── code_split/                 # 切分/复制后的待翻译文件
│   ├── code_split_output/          # AI 翻译后的中间输出
│   └── repair/                     # 修复插件链中间文件
├── templates/
│   └── system_prompt.txt           # 系统提示词模板
├── plugins/
│   ├── checks/                     # 推荐放检查插件
│   └── repairs/                    # 推荐放修复插件
└── src/comment2zh/
    ├── cli.py                      # CLI 参数解析
    ├── config.py                   # 配置加载与路径解析
    ├── discovery.py                # 输入文件扫描
    ├── merger.py                   # 分块结果合并
    ├── models.py                   # 配置数据模型
    ├── pipeline.py                 # 主流程编排
    ├── plugins.py                  # 插件加载与执行框架
    ├── postprocess.py              # 旧后处理逻辑保留区
    ├── prompting.py                # Prompt 加载
    ├── splitter.py                 # C/C++ 文件安全切分
    ├── processor/
    │   └── file_translator.py      # 单文件翻译、检查和并发调度
    ├── translator/
    │   └── openai_client.py        # OpenAI 兼容 API 客户端
    └── utils/
        ├── paths.py
        └── text.py
```

## 快速运行

### 1. 安装依赖

项目依赖至少包括：

```bash
pip install openai tqdm
```

### 2. 配置 API Key

`config.json` 中的 `api_key_env` 指定环境变量名，例如：

```json
"api_key_env": "OPENAI_API_KEY"
```

运行前需要设置对应环境变量。

Linux/macOS/Git Bash 示例：

```bash
export OPENAI_API_KEY="你的 API Key"
```

Windows PowerShell 示例：

```powershell
$env:OPENAI_API_KEY="你的 API Key"
```

### 3. 放入输入文件

把待处理的 `.c/.h/.cpp` 文件放入：

```text
code_input/
```

### 4. 试运行扫描

```bash
python main.py --dry-run
```

该命令只扫描文件并统计哪些文件会切分，不会调用 AI。

### 5. 执行完整流程

```bash
python main.py
```

## CLI 参数

入口：

```bash
python main.py [run] [options]
```

当前支持参数：

| 参数 | 说明 |
|---|---|
| `--config` | 指定配置文件，默认 `config.json` |
| `--input-dir` | 覆盖配置中的输入目录 |
| `--output-dir` | 覆盖配置中的输出目录 |
| `--workers` | 覆盖并发线程数 |
| `--extensions` | 覆盖处理扩展名，例如 `--extensions .c .h` |
| `--skip-fix` | 兼容旧参数，会把 `fix_backslash_comments` 设为 false |
| `--dry-run` | 只扫描和统计，不调用模型 |

注意：当前修复能力已经插件化，推荐通过 `repair_scripts` 控制修复脚本，而不是依赖 `--skip-fix`。

## 配置说明

参考 `config.example.json`：

```json
{
  "api_key_env": "OPENAI_API_KEY",
  "base_url": "https://your-openai-compatible-endpoint/v1",
  "model": "gpt-4.1",
  "temperature": 0.1,
  "top_p": 1,
  "timeout": 600,
  "max_workers": 4,
  "input_dir": "code_input",
  "output_dir": "code_output",
  "split_dir": "temp/code_split",
  "split_output_dir": "temp/code_split_output",
  "repair_temp_dir": "temp/repair",
  "system_prompt_path": "templates/system_prompt.txt",
  "file_extensions": [".c", ".h", ".cpp"],
  "chunk_threshold_bytes": 20000,
  "chunk_max_bytes": 20000,
  "chunk_min_bytes": 10000,
  "encoding": "utf-8",
  "fix_backslash_comments": false,
  "overwrite_output": true,
  "retry_count": 0,
  "retry_base_delay_seconds": 1.0,
  "retry_max_delay_seconds": 30.0,
  "check_scripts": [],
  "repair_scripts": ["plugins/repairs/fix_backslash_comments.py"],
  "max_translate_attempts": 1,
  "plugin_timeout_seconds": 60
}
```

### API 配置

| 字段 | 说明 |
|---|---|
| `api_key_env` | API Key 所在环境变量名 |
| `base_url` | OpenAI 兼容接口地址 |
| `model` | 模型名 |
| `temperature` | 采样温度，建议较低，减少代码结构漂移 |
| `top_p` | nucleus sampling 参数 |
| `timeout` | 单次 API 请求超时时间，秒 |
| `extra_body` | 可选，传给 OpenAI SDK 的扩展请求体 |

### 路径配置

| 字段 | 说明 |
|---|---|
| `input_dir` | 原始代码输入目录 |
| `output_dir` | 最终输出目录 |
| `split_dir` | 切分/复制后的待翻译目录 |
| `split_output_dir` | AI 翻译后输出目录 |
| `repair_temp_dir` | 修复插件链中间文件目录 |
| `system_prompt_path` | 系统提示词路径 |
| `log_dir` | 可选，切分报告日志目录 |

相对路径会按项目根目录解析。

### 处理配置

| 字段 | 说明 |
|---|---|
| `file_extensions` | 需要处理的文件扩展名 |
| `encoding` | 文件读写编码 |
| `max_workers` | 并发翻译线程数 |
| `chunk_threshold_bytes` | 文件大于等于该值时进入切分 |
| `chunk_max_bytes` | 单个分块目标最大大小 |
| `chunk_min_bytes` | 单个分块目标最小大小 |
| `overwrite_output` | 运行前是否清理中间目录和输出目录 |
| `preserve_input_encoding` | 当前保留字段，尚未完整实现输入编码保留 |

### API 请求重试配置

| 字段 | 说明 |
|---|---|
| `retry_count` | 单次 API 请求失败后的重试次数 |
| `retry_base_delay_seconds` | 指数退避初始等待秒数 |
| `retry_max_delay_seconds` | 指数退避最大等待秒数 |

当前只会对以下情况重试：

- 网络连接错误
- 请求超时
- 限流错误
- HTTP `408`
- HTTP `409`
- HTTP `429`
- HTTP `5xx`

参数错误等普通 `4xx` 不会重试。

### 插件配置

| 字段 | 说明 |
|---|---|
| `check_scripts` | 检查插件脚本列表 |
| `repair_scripts` | 修复插件脚本列表 |
| `max_translate_attempts` | 检查失败后整文件重新翻译的最大尝试次数 |
| `plugin_timeout_seconds` | 单个插件调用超时时间；小于等于 0 或 `null` 表示不限制 |

## 检查插件开发

检查插件用于判断 AI 输出是否可接受。它运行在“AI 翻译”之后、“合并”之前。

插件文件可放在任意位置，推荐放在：

```text
plugins/checks/
```

然后写入 `config.json`：

```json
"check_scripts": [
  "plugins/checks/check_not_empty.py"
]
```

### 函数协议

检查插件需要定义 `check()` 或 `main()`：

```python
def check(before_path: str, after_path: str) -> bool:
    return True
```

参数：

| 参数 | 说明 |
|---|---|
| `before_path` | 翻译前文件路径，通常位于 `split_dir` |
| `after_path` | 翻译后文件路径，通常位于 `split_output_dir` |

返回值：

- 必须严格返回 `True` 才视为通过。
- 返回 `False`、`None`、字符串、数字或抛异常，都视为检查失败。

### 示例：检查输出非空

```python
from pathlib import Path


def check(before_path: str, after_path: str) -> bool:
    return Path(after_path).read_text(encoding="utf-8").strip() != ""
```

### 示例：检查翻译后行数不要过度变化

```python
from pathlib import Path


def check(before_path: str, after_path: str) -> bool:
    before_lines = Path(before_path).read_text(encoding="utf-8").splitlines()
    after_lines = Path(after_path).read_text(encoding="utf-8").splitlines()
    return abs(len(before_lines) - len(after_lines)) <= 10
```

## 修复插件开发

修复插件用于处理合并后的最终文件。它运行在“合并”之后。

插件文件推荐放在：

```text
plugins/repairs/
```

然后写入 `config.json`：

```json
"repair_scripts": [
  "plugins/repairs/fix_backslash_comments.py",
  "plugins/repairs/your_custom_repair.py"
]
```

### 函数协议

修复插件需要定义 `repair()` 或 `main()`：

```python
def repair(input_path: str, output_path: str) -> bool:
    return True
```

参数：

| 参数 | 说明 |
|---|---|
| `input_path` | 上一步修复结果，或最初的合并后文件 |
| `output_path` | 本插件必须写入的输出文件 |

返回值：

- 必须严格返回 `True` 才视为成功。
- 返回其他值或抛异常会使整个流程失败。

重要约定：

- 修复插件必须写入 `output_path`。
- 不要只原地修改 `input_path`。
- 如果插件不需要修改内容，也应复制 `input_path` 到 `output_path` 后返回 `True`。

### 示例：透传修复插件

```python
import shutil


def repair(input_path: str, output_path: str) -> bool:
    shutil.copy2(input_path, output_path)
    return True
```

### 示例：追加文件尾注释

```python
import shutil
from pathlib import Path


def repair(input_path: str, output_path: str) -> bool:
    shutil.copy2(input_path, output_path)
    path = Path(output_path)
    text = path.read_text(encoding="utf-8")
    path.write_text(text + "\n/* repaired */\n", encoding="utf-8")
    return True
```

## 反斜杠修复插件

宏续行中的反斜杠位置对 C 预处理语法很敏感。项目提供了一个普通修复插件：

```text
plugins/repairs/fix_backslash_comments.py
```

它已经不是内置逻辑，必须显式写入 `repair_scripts` 才会执行：

```json
"repair_scripts": ["plugins/repairs/fix_backslash_comments.py"]
```

`fix_backslash_comments` 字段目前只作为旧配置兼容字段保留，推荐设置为：

```json
"fix_backslash_comments": false
```

维护时不要再向 `pipeline.py` 或 `plugins.py` 添加新的内置修复逻辑。新增修复能力应优先实现为 `plugins/repairs/` 下的普通插件。

## 关键模块维护说明

### `src/comment2zh/pipeline.py`

主流程编排，只负责串联阶段，不应塞入具体业务细节。

当前关键调用顺序：

1. `collect_input_files()`
2. `_copy_small_or_split_large()`
3. `FileTranslator.run()`
4. `merge_split_output_files()`
5. `RepairPluginRunner.run()`

维护原则：

- 新阶段如果是可扩展能力，优先做成独立模块或插件。
- 不要把具体检查/修复规则硬编码到这里。

### `src/comment2zh/processor/file_translator.py`

负责单文件翻译、检查失败重译、并发调度和进度条。

`max_translate_attempts` 控制的是“检查失败后的整文件重译次数”，不同于 API 请求重试。

维护原则：

- 不要在这里写具体检查规则。
- 检查逻辑应通过 `CheckPluginRunner` 调用。
- 失败信息应尽量包含具体插件返回原因，方便定位。

### `src/comment2zh/translator/openai_client.py`

只负责 OpenAI 兼容 API 调用。

当前实现特点：

- SDK 内置重试已关闭，项目自己控制重试。
- 只对超时、限流、网络连接、`408/409/429/5xx` 重试。
- 非重试类错误会直接失败。

维护原则：

- 不要把文件读写、检查插件、合并逻辑放到 API 客户端里。
- 新增供应商扩展参数时，优先通过 `extra_body` 配置传入。

### `src/comment2zh/splitter.py`

负责大文件安全切分，来源于旧项目中相对成熟的分块脚本。

维护原则：

- 修改切分算法要谨慎。
- 优先用真实 C/H 文件和边界样例验证。
- 特别注意字符串、块注释、宏续行、空行边界。

### `src/comment2zh/merger.py`

负责把 `.partN` 翻译结果合并回原文件。

维护原则：

- `.partN` 命名规则不要随意改，否则会影响旧切分产物兼容性。
- `merge_split_output_files()` 返回输出文件列表，供修复插件链使用。

### `src/comment2zh/plugins.py`

负责插件动态加载、超时控制、检查插件链和修复插件链。

维护原则：

- 插件协议要保持简单：路径字符串入参，布尔返回值。
- 检查插件失败不应直接终止整个流程，而是触发当前文件重译，直到达到上限。
- 修复插件失败应终止流程，因为最终输出可能不完整。

## Prompt 维护

系统提示词位于：

```text
templates/system_prompt.txt
```

当前 Prompt 的核心约束是：

- 英文注释替换为中文注释。
- 可以给明显需要说明的位置补充中文注释。
- 除注释外不得修改任何代码、标识符、预处理条件或语句结构。
- 输入可能是不完整分块，禁止补全上下文。
- 返回时只输出代码内容。

维护 Prompt 时要注意：

- 不要让模型“优化代码”或“重构代码”。
- 不要要求模型解释输出，否则会污染代码文件。
- 对宏续行反斜杠的约束要保留。

## 中间目录和输出目录

默认路径：

| 目录 | 内容 |
|---|---|
| `code_input/` | 原始输入 |
| `temp/code_split/` | 切分/复制后的待翻译文件 |
| `temp/code_split_output/` | 翻译后的分块输出 |
| `temp/repair/` | 修复插件链中间文件 |
| `code_output/` | 最终输出 |

当 `overwrite_output=true` 时，每次正式运行前会清理：

- `split_dir`
- `split_output_dir`
- `output_dir`
- `repair_temp_dir`

因此不要把需要长期保留的文件放进这些目录。

## 验证建议

### 静态编译检查

```bash
python -m compileall "F:/Python_Project/代码注释转中文新/src/comment2zh" "F:/Python_Project/代码注释转中文新/plugins" "F:/Python_Project/代码注释转中文新/main.py"
```

### dry-run

```bash
python "F:/Python_Project/代码注释转中文新/main.py" --dry-run
```

### 插件验证

建议维护者准备两个检查插件：

1. 永远返回 `True`，验证插件链正常通过。
2. 永远返回 `False`，设置 `max_translate_attempts=2`，验证失败重译和最终失败清单。

建议准备一个透传修复插件：

```python
import shutil


def repair(input_path: str, output_path: str) -> bool:
    shutil.copy2(input_path, output_path)
    return True
```

用它验证修复链路径传递是否正常。

## 常见问题

### 1. 为什么检查插件运行在合并前？

因为 AI 翻译的实际单位是 `split_dir` 中的文件。大文件被切成多个 `.partN` 后，每个分块都是独立翻译单元。检查应尽早发现单个翻译单元的问题，避免把错误带入合并阶段。

### 2. API 请求重试和 `max_translate_attempts` 有什么区别？

`retry_count` 是一次 API 请求由于网络、超时、限流、5xx 等失败后的请求级重试。

`max_translate_attempts` 是模型成功返回后，检查插件认为输出不合格，于是整文件重新翻译的次数。

两者是不同层级，不能混用。

### 3. 修复插件为什么要写 `output_path`？

修复插件链需要明确的输入输出关系：

```text
合并文件 -> 插件1输出 -> 插件2输出 -> ... -> 最终文件
```

如果插件原地修改 `input_path`，链路会变得不清晰，也更难排查问题。

### 4. 反斜杠修复为什么不是内置？

为了保持插件系统一致性和可维护性，反斜杠修复已经独立为普通修复插件：

```text
plugins/repairs/fix_backslash_comments.py
```

是否执行完全由 `repair_scripts` 决定。

### 5. 输出为空怎么办？

可以添加检查插件，例如 `plugins/checks/check_not_empty.py`，检查 `after_path` 内容非空。检查失败会触发重新翻译。

## 维护原则

- `pipeline.py` 只做编排，不写具体检查/修复规则。
- 检查规则放到 `plugins/checks/`。
- 修复规则放到 `plugins/repairs/`。
- API 逻辑只放在 `translator/openai_client.py`。
- 文件切分和合并逻辑应谨慎修改，优先写样例验证。
- 新增配置时同步更新：
  - `models.py`
  - `config.py`
  - `config.example.json`
  - 本 README
