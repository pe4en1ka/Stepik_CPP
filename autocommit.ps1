#Requires -Version 7
$ErrorActionPreference = "Stop"

$RepoPath = "C:\Users\tmame\MIPT_1"
$GitPath = "C:\Program Files\Git\bin\git.exe"
$GitHubUser = "pe4en1ka"
$RepoName = "Stepik_CPP"
$BranchName = "MIPT_1"

# Зашифрованный токен (замените на свой)
$EncryptedToken = "01000000d08c9ddf0115d1118c7a00c04fc297eb010000002225ea553bdba44cbb3c381e03821e6000000000020000000000106600000001000020000000977944d31d632d8fbe1c320b0cbc0af1d9a6e66df69a24e62782391cb8860d8d000000000e80000000020000200000008eb38fdaa570b33ad58495d09cf7210788fc331706a301be6a2b3d5467cf4ee160000000efbb092244a94a1f0914f57fdf612a4634bd0e34af3f2b4c29d574118d99c932cb63b13db8a7b5bd1eacc24c98344a6a92f72e28e2d16bb018d7c4fb669c0c10a87eff44daa3285444c1bd309d3f53856445c6411db7e5d563ae91867d3abf61400000008458753e87770f55ee3ac07fca13c55c1e18947e3459a0987f7ce57ce2c457be41ab3cca9359ab04f1ed472c316c5cbad5a55079ac0f03c43d1a36d3249cac10"

function Log {
    param([string]$Message)
    $timestamp = [System.DateTime]::Now.ToString("yyyy-MM-dd HH:mm:ss")
    Write-Host "$timestamp | $Message" -ForegroundColor Cyan
}

function Get-GitHubToken {
    # Расшифровка токена
    $SecureToken = ConvertTo-SecureString -String $EncryptedToken
    $BSTR = [System.Runtime.InteropServices.Marshal]::SecureStringToBSTR($SecureToken)
    return [System.Runtime.InteropServices.Marshal]::PtrToStringAuto($BSTR)
}

try {
    # Проверка репозитория
    if (-not (Test-Path (Join-Path $RepoPath ".git"))) {
        Log "Ошибка: Репозиторий не найден"
        exit 1
    }

    Set-Location -Path $RepoPath

    # Получение токена
    $GitHubToken = Get-GitHubToken

    # Формируем URL с токеном
    $RemoteUrl = "https://${GitHubToken}@github.com/${GitHubUser}/${RepoName}.git"
    Log "Используем URL: $($RemoteUrl.Replace($GitHubToken, '***'))"

    # Настройка Git
    & $GitPath config --global user.name "Auto Committer"
    & $GitPath config --global user.email "auto@commit"
    & $GitPath remote set-url origin $RemoteUrl

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

    # Отправка изменений с явной передачей учетных данных
    Log "Отправляем изменения в ветку $BranchName..."
    & $GitPath -c http.extraHeader="Authorization: Basic $( [Convert]::ToBase64String([Text.Encoding]::ASCII.GetBytes("${GitHubToken}:")) )" push origin $BranchName

    if ($LASTEXITCODE -ne 0) {
        Log "Ошибка при отправке изменений (код $LASTEXITCODE)"
        exit 1
    }

    Log "УСПЕХ: Изменения отправлены в $RepoName!"
}
catch {
    Log "КРИТИЧЕСКАЯ ОШИБКА: $_"
    exit 1
}
finally {
    # Очищаем токен из памяти
    $GitHubToken = $null
    [System.GC]::Collect()
}

Read-Host "Нажмите Enter для выхода"