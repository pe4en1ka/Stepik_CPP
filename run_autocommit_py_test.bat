@echo off
chcp 1251 > nul

set "PYTHON=C:\Users\tmame\MIPT_cpp\.venv\Scripts\python.exe"
set "SCRIPT=C:\Users\tmame\MIPT_cpp\autocommit.py"

echo [%date% %time%] Запуск авто-коммита
"%PYTHON%" "%SCRIPT%"

if %errorlevel% neq 0 (
    echo [%date% %time%] ОШИБКА: Код %errorlevel%
) else (
    echo [%date% %time%] УСПЕШНО
)

echo [%date% %time%] Завершение работы
timeout /t 30