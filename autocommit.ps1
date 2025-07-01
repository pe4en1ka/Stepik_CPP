#Requires -Version 7
$ErrorActionPreference = "Stop"

$RepoPath = "C:\Users\tmame\MIPT_1"
$GitPath = "C:\Program Files\Git\bin\git.exe"
$GitHubToken = "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"  # ЗАМЕНИТЕ НА РЕАЛЬНЫЙ ТОКЕН
$GitHubUser = "pe4en1ka"  # Ваш реальный GitHub username
$RepoName = "Stepik_CPP"   # Реальное название репозитория
$BranchName = "MIPT_1"       # Основная ветка (проверьте в репозитории)

function Log {
    param([string]$Message)
    $timestamp = [System.DateTime]::Now.ToString("yyyy-MM-dd HH:mm:ss")
    Write-Host "[$timestamp] $Message" -ForegroundColor Cyan
}

try {
    # Проверка репозитория
    if (-not (Test-Path (Join-Path $RepoPath ".git"))) {
        Log "Ошибка: Репозиторий не найден"
        exit 1
    }

    Set-Location -Path $RepoPath

    # Формируем URL с токеном
    $RemoteUrl = "https://${GitHubToken}@github.com/${GitHubUser}/${RepoName}.git"
    Log "Используем URL: $($RemoteUrl.Replace($GitHubToken, '***'))"

    # Настройка Git
    & $GitPath config --global user.name "Auto Committer"
    & $GitPath config --global user.email "auto@commit"
    & $GitPath remote set-url origin $RemoteUrl

    # Проверка подключения
    Log "Проверяем подключение к GitHub..."
    $check = & $GitPath ls-remote 2>&1
    if ($LASTEXITCODE -ne 0) {
        Log "Ошибка подключения: $check"
        Log "Проверьте:"
        Log "1. Корректность токена"
        Log "2. Наличие репозитория $RepoName у пользователя $GitHubUser"
        Log "3. Доступность GitHub из сети"
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
    & $GitPath commit -m "Автоматический коммит $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
    if (-not $?) {
        Log "Ошибка при создании коммита"
        exit 1
    }

    # Отправка изменений
    Log "Отправляем изменения в ветку $BranchName..."
    & $GitPath push origin $BranchName -f
    if (-not $?) {
        Log "Ошибка при отправке изменений"
        exit 1
    }

    Log "УСПЕХ: Изменения отправлены в $RepoName!"
}
catch {
    Log "КРИТИЧЕСКАЯ ОШИБКА: $_"
    exit 1
}

Read-Host "Нажмите Enter для выхода"