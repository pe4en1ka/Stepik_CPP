#Requires -Version 7
$ErrorActionPreference = "Stop"

$RepoPath = "C:\Users\tmame\MIPT_cpp"
$GitPath = "C:\Program Files\Git\bin\git.exe"
$SshKeyPath = "C:\Users\tmame\.ssh\github_rsa"
$SshAgentPath = "C:\Program Files\Git\usr\bin\ssh-agent.exe"
$SshAddPath = "C:\Program Files\Git\usr\bin\ssh-add.exe"

function Log {
    param([string]$Message)
    $timestamp = [System.DateTime]::Now.ToString("yyyy-MM-dd HH:mm:ss")
    Write-Host "[$timestamp] $Message" -ForegroundColor Cyan
}

function Initialize-SshKey {
    $sshDir = Split-Path $SshKeyPath
    if (-not (Test-Path $sshDir)) {
        Log "Создаем папку .ssh..."
        New-Item -ItemType Directory -Path $sshDir -Force | Out-Null
    }

    # Удаляем старые ключи, если существуют
    if (Test-Path $SshKeyPath) {
        Remove-Item $SshKeyPath -Force
    }
    if (Test-Path "$SshKeyPath.pub") {
        Remove-Item "$SshKeyPath.pub" -Force
    }

    Log "Генерируем SSH-ключ..."
    # Автоматически подтверждаем перезапись
    & "ssh-keygen" -t rsa -b 4096 -f $SshKeyPath -N '""' -q

    # Запускаем ssh-agent
    if (Test-Path $SshAgentPath) {
        Start-Process $SshAgentPath -WindowStyle Hidden
        Start-Sleep -Seconds 1

        # Добавляем ключ
        if (Test-Path $SshAddPath) {
            & $SshAddPath $SshKeyPath
        }
    }

    $publicKey = Get-Content "$SshKeyPath.pub"
    Log "`n!!! ДОБАВЬТЕ ЭТОТ КЛЮЧ В GITHUB !!!"
    Log "Перейдите: https://github.com/settings/ssh/new"
    Log "Ключ: $publicKey"
    Log "`nПосле добавления ключа запустите скрипт снова"
    exit 0
}

try {
    if (-not (Test-Path $SshKeyPath)) {
        Initialize-SshKey
    }

    if (-not (Test-Path (Join-Path $RepoPath ".git"))) {
        Log "Ошибка: Репозиторий не найден"
        exit 1
    }

    Set-Location -Path $RepoPath

    # Явно указываем путь к SSH
    $sshPath = "C:\Program Files\Git\usr\bin\ssh.exe"
    $env:GIT_SSH_COMMAND = "`"$sshPath`" -i `"$SshKeyPath`" -o IdentitiesOnly=yes"

    & $GitPath --version
    if (-not $?) {
        Log "Ошибка: Git не доступен"
        exit 1
    }

    # ПРАВИЛЬНАЯ ПРОВЕРКА SSH
    Log "Проверяем SSH-подключение к GitHub..."
    $sshTest = & $sshPath -T git@github.com -i $SshKeyPath -o StrictHostKeyChecking=no 2>&1 | Out-String

    if ($sshTest -match "successfully authenticated") {
        Log "SSH подключение успешно"
    } else {
        Log "Ошибка SSH: $sshTest"
        Initialize-SshKey
    }

    # Добавляем изменения
    Log "Добавляем изменения в staging..."
    & $GitPath add --all .
    if (-not $?) {
        Log "Ошибка при добавлении файлов"
        exit 1
    }

    $stagedFiles = & $GitPath diff --name-only --cached
    if (-not $stagedFiles) {
        Log "Нет изменений для коммита"
        exit 0
    }

    Log "Найдено файлов для коммита: $($stagedFiles.Count)"

    # Коммит файлов
    foreach ($file in $stagedFiles) {
        $fullPath = Join-Path $RepoPath $file
        if (-not (Test-Path $fullPath)) {
            Log "Файл не существует: $fullPath"
            continue
        }

        $fileName = [System.IO.Path]::GetFileName($file)
        $isCpp = $file -match '\.(cpp|cxx|cc|h|hpp)$'

        if ($isCpp) {
            $commitMessage = $fileName
            Log "Коммитим CPP файл: $fileName"
        } else {
            $commitMessage = "Trash"
            Log "Коммитим файл: $fileName (Trash)"
        }

        & $GitPath commit -m $commitMessage -- $file
        if (-not $?) {
            Log "Ошибка при коммите файла $fileName"
        }
    }

    # Отправка изменений
    Log "Отправляем изменения..."
    $env:GIT_TERMINAL_PROMPT = "0"
    & $GitPath push origin MIPT -f
    if (-not $?) {
        Log "Ошибка при отправке изменений"
        exit 1
    }

    Log "Выполнение завершено успешно"
}
catch {
    Log "КРИТИЧЕСКАЯ ОШИБКА: $_"
    exit 1
}
finally {
    Remove-Item env:\GIT_TERMINAL_PROMPT -ErrorAction Ignore
    Remove-Item env:\GIT_SSH_COMMAND -ErrorAction Ignore
}

Read-Host "Нажмите Enter для выхода"