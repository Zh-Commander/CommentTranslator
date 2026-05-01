def notify(task_info: dict) -> bool:
    print(f"[notification] {task_info['status']}: {task_info['message']}")
    return True
