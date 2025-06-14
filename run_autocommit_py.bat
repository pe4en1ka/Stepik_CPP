@echo off
set PYTHON_PATH="C:\Users\tmame\MIPT_cpp\.venv\Scripts\python.exe"
set SCRIPT_PATH="C:\Users\tmame\MIPT_cpp\autocommit.py"
set LOG_PATH="C:\Users\tmame\autocommit.log"

echo [%date% %time%] Starting autocommit >> %LOG_PATH%
%PYTHON_PATH% %SCRIPT_PATH% >> %LOG_PATH% 2>&1
echo [%date% %time%] Finished with code %errorlevel% >> %LOG_PATH%