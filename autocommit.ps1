#Requires -Version 7
$ErrorActionPreference = "Stop"

$RepoPath = "C:\Users\tmame\MIPT_1"
$GitPath = "C:\Program Files\Git\bin\git.exe"
$GitHubToken = "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"  # ЗАМЕНИТЕ НА РЕАЛЬНЫЙ ТОКЕН
$GitHubUser = "tmame"  # Ваш GitHub username
$RepoName = "MIPT_1"   # Название репозитория

function Log {
    param([string]$Message)
    $timestamp = [System.DateTime]::Now.ToString("yyyy-MM-dd HH:mm:ss")
    Write-Host "[$timestamp] $Message" -ForegroundColor Cyan
}

# Инструкция по получению токена:
# 1. Перейдите: https://github.com/settings/tokens
# 2. Создайте токен с правами "repo" (полный доступ к репозиториям)
# 3. Скопируйте токен (начинается с ghp_)
# 4. Вставьте его в строку $GitHubToken выше

try {
    # Проверка репозитория
    if (-not (Test-Path (Join-Path $RepoPath ".git"))) {
        Log "Ошибка: Репозиторий не найден"
        exit 1
    }

    Set-Location -Path $RepoPath

    # Настройка Git
    & $GitPath config --global user.name "Auto Committer"
    & $GitPath config --global user.email "auto@commit"
    & $GitPath remote set-url origin "https://$GitHubToken@github.com/$GitHubUser/$RepoName.git"

    # Проверка Git
    & $GitPath --version | Out-Null
    if (-not $?) {
        Log "Ошибка: Git не доступен"
        exit 1
    }

    # Добавление изменений
    Log "Добавляем изменения..."
    & $GitPath add --all .
    if (-not $?) {
        Log "Ошибка при добавлении файлов"
        exit 1
    }

    # Проверка изменений
    $status = & $GitPath status --porcelain
    if (-not $status) {
        Log "Нет изменений для коммита"
        exit 0
    }

    Log "Найдено изменений: $($status.Count)"

    # Коммит изменений
    Log "Создаем коммит..."
    & $GitPath commit -m "Автоматический коммит"
    if (-not $?) {
        Log "Ошибка при создании коммита"
        exit 1
    }

    # Отправка изменений
    Log "Отправляем изменения..."
    & $GitPath push origin MIPT_1 -f
    if (-not $?) {
        Log "Ошибка при отправке изменений"
        Log "Совет: Попробуйте заменить # на %23 в названии репозитория"
        Log "Выполните вручную:"
        Log "git remote set-url origin `"https://$GitHubToken@github.com/$GitHubUser/MIPT%231.git`""
        Log "git push origin MIPT_1 -f"
        exit 1
    }

    Log "УСПЕХ: Изменения отправлены!"
}
catch {
    Log "КРИТИЧЕСКАЯ ОШИБКА: $_"
    exit 1
}

Read-Host "Нажмите Enter для выхода"