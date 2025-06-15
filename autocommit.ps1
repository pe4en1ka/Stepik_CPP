#Requires -Version 5
$ErrorActionPreference = "Stop"

# Настройки
$RepoPath = "C:\Users\tmame\MIPT_cpp"
$GitPath = "C:\Program Files\Git\bin\git.exe"

function Log {
    param([string]$Message)
    Write-Host "[$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')] $Message" -ForegroundColor Cyan
}

try {
    # Проверка существования репозитория
    if (-not (Test-Path (Join-Path $RepoPath ".git"))) {
        Log "Ошибка: Репозиторий не найден"
        exit 1
    }

    Set-Location -Path $RepoPath

    # Проверка доступности Git
    & $GitPath --version
    if (-not $?) {
        Log "Ошибка: Git не доступен"
        exit 1
    }

    # Добавляем все изменения
    Log "Добавляем изменения в staging..."
    & $GitPath add --all .
    if (-not $?) {
        Log "Ошибка при добавлении файлов"
        exit 1
    }

    # Получаем список добавленных файлов
    $stagedFiles = & $GitPath diff --name-only --cached
    if (-not $stagedFiles) {
        Log "Нет изменений для коммита"
        exit 0
    }

    Log "Найдено файлов для коммита: $($stagedFiles.Count)"

    # Коммитим каждый файл отдельно
    foreach ($file in $stagedFiles) {
        $fullPath = Join-Path $RepoPath $file
        if (-not (Test-Path $fullPath)) {
            Log "Файл не существует: $fullPath"
            continue
        }

        $fileName = [System.IO.Path]::GetFileName($file)
        $isCpp = $file -match '\.cpp$'

        if ($isCpp) {
            $commitMessage = $fileName
            Log "Коммитим CPP файл: $fileName"
        } else {
            $commitMessage = "Trash"
            Log "Коммитим файл: $fileName (Trash)"
        }

        # Коммит файла
        & $GitPath commit -m $commitMessage -- $file
        if (-not $?) {
            Log "Ошибка при коммите файла $fileName"
            continue
        }

        # Пуш изменений
        Log "Отправляем изменения..."
        & $GitPath push origin MIPT -f
        if (-not $?) {
            Log "Ошибка при отправке изменений"
        }
    }

    Log "Выполнение завершено успешно"
}
catch {
    Log "КРИТИЧЕСКАЯ ОШИБКА: $_"
    exit 1
}

# Задержка для просмотра результатов
Read-Host "Нажмите Enter для выхода"