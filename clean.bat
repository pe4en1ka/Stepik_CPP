@echo off
echo === Очистка проекта ===

:: Удаление всех EXE файлов в корневой директории
del /Q "%~dp0*.exe" 2>nul
echo Удалены EXE файлы в корне

:: Удаление всех временных файлов сборки
if exist "%~dp0build\" (
    rmdir /S /Q "%~dp0build"
    echo Удалена папка build
)

:: Дополнительные файлы для удаления (по необходимости)
del /Q "%~dp0*.o" 2>nul
del /Q "%~dp0*.a" 2>nul
del /Q "%~dp0*.ilk" 2>nul
del /Q "%~dp0*.pdb" 2>nul
del /Q "%~dp0*.sln" 2>nul
del /Q "%~dp0*.vcxproj*" 2>nul

echo Проект успешно очищен!
timeout /t 3