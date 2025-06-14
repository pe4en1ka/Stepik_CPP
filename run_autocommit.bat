@echo off
echo [START] AutoCommit diagnostic script
echo Timestamp: %date% %time%

"C:\Program Files\Git\bin\bash.exe" -c "./autocommit.sh"

echo [END] Exit code: %errorlevel%
timeout /t 30@echo off
echo [START] AutoCommit script
"C:\Program Files\Git\bin\bash.exe" -c "./autocommit.sh"
echo [END] Exit code: %errorlevel%
timeout /t 5