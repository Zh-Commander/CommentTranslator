from __future__ import annotations

import os
import time
from typing import Any

import openai
from openai import OpenAI

from ..models import OpenAISettings, ProcessingSettings


class OpenAIClient:
    def __init__(self, settings: OpenAISettings, processing: ProcessingSettings):
        api_key = os.getenv(settings.api_key_env)
        if not api_key:
            raise RuntimeError(f"environment variable {settings.api_key_env} is not set")

        client_kwargs: dict[str, Any] = {"api_key": api_key, "max_retries": 0}
        if settings.base_url:
            client_kwargs["base_url"] = settings.base_url

        self._client = OpenAI(**client_kwargs)
        self._settings = settings
        self._retry_count = processing.retry_count
        self._retry_base_delay_seconds = processing.retry_base_delay_seconds
        self._retry_max_delay_seconds = processing.retry_max_delay_seconds

    def _should_retry(self, exc: Exception) -> bool:
        if isinstance(exc, (openai.APIConnectionError, openai.APITimeoutError, openai.RateLimitError)):
            return True

        if isinstance(exc, openai.InternalServerError):
            return True

        if isinstance(exc, openai.APIStatusError):
            return exc.status_code in {408, 409, 429} or exc.status_code >= 500

        return False

    def _retry_delay_seconds(self, attempt: int) -> float:
        delay = self._retry_base_delay_seconds * (2 ** (attempt - 1))
        return min(delay, self._retry_max_delay_seconds)

    def translate(self, system_prompt: str, user_prompt: str) -> str:
        request_kwargs: dict[str, Any] = {
            "model": self._settings.model,
            "messages": [
                {"role": "system", "content": system_prompt},
                {"role": "user", "content": user_prompt},
            ],
            "temperature": self._settings.temperature,
            "top_p": self._settings.top_p,
            "timeout": self._settings.timeout,
        }
        if self._settings.extra_body:
            request_kwargs["extra_body"] = self._settings.extra_body

        attempts = self._retry_count + 1
        last_error: Exception | None = None
        for attempt in range(1, attempts + 1):
            try:
                response = self._client.chat.completions.create(**request_kwargs)
                return response.choices[0].message.content or ""
            except Exception as exc:  # noqa: BLE001
                last_error = exc
                if attempt == attempts or not self._should_retry(exc):
                    break
                delay = self._retry_delay_seconds(attempt)
                time.sleep(delay)

        raise RuntimeError(f"request failed after {attempts} attempt(s): {last_error}") from last_error
