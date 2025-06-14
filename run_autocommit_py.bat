@echo off
setlocal enabledelayedexpansion

:: Путь к Python интерпретатору
set "PYTHON=C:\Users\tmame\MIPT_cpp\.venv\Scripts\python.exe"

:: Путь к скрипту
set "SCRIPT=C:\Users\tmame\MIPT_cpp\autocommit.py"

:: Проверка существования файлов
if not exist "%PYTHON%" (
    echo ОШИБКА: Python не найден по пути: %PYTHON%
    pause
    exit /b 1
)

if not exist "%SCRIPT%" (
    echo ОШИБКА: Скрипт не найден по пути: %SCRIPT%
    pause
    exit /b 1
)

:: Запуск скрипта
echo [%date% %time%] Запуск авто-коммита
"%PYTHON%" "%SCRIPT%"

:: Обработка результата
if errorlevel 1 (
    echo [%date% %time%] ОШИБКА: Скрипт завершился с кодом %errorlevel%
) else (
    echo [%date% %time%] УСПЕХ: Скрипт выполнен успешно
)

echo [%date% %time%] Завершение работы
timeout /t 30 /nobreak >nul
exit /b 0