# Minimal PowerShell autocommit script
#Requires -Version 5
$ErrorActionPreference = "Stop"

# Configuration
$RepoPath = "C:\Users\tmame\MIPT_cpp"
$GitPath = "C:\Program Files\Git\bin\git.exe"
$SshKeyPath = Join-Path $env:USERPROFILE ".ssh\github_rsa"

# Simple logging function
function Write-Log {
    param([string]$msg)
    Write-Host "[$(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')] $msg"
}

try {
    # SSH key setup
    if (-not (Test-Path $SshKeyPath)) {
        $sshDir = [System.IO.Path]::GetDirectoryName($SshKeyPath)
        if (-not (Test-Path $sshDir)) {
            New-Item -ItemType Directory -Path $sshDir -Force | Out-Null
        }

        Start-Process ssh-keygen -ArgumentList "-t rsa -b 4096 -f `"$SshKeyPath`" -N `"`"`" -q" -Wait
        Write-Log "SSH key generated. Add to GitHub:"
        Write-Log (Get-Content "$SshKeyPath.pub")
        Write-Log "After adding key, rerun script"
        exit 0
    }

    # Repository check
    Set-Location $RepoPath
    if (-not (Test-Path ".git")) { throw "Repository not found" }

    # Git operations
    & $GitPath add --all .
    $staged = & $GitPath diff --name-only --cached

    if (-not $staged) { exit 0 }

    foreach ($file in $staged) {
        $name = [System.IO.Path]::GetFileName($file)
        $msg = if ($file -match '\.(cpp|cxx|cc|h|hpp)$') { $name } else { "Trash" }

        & $GitPath commit -m $msg -- $file
    }

    # Push with SSH
    $env:GIT_SSH_COMMAND = "ssh -i `"$SshKeyPath`" -o IdentitiesOnly=yes"
    & $GitPath push origin MIPT -f

    Write-Log "Operation completed"
}
catch {
    Write-Log "ERROR: $_"
    exit 1
}
finally {
    Remove-Item env:\GIT_SSH_COMMAND -ErrorAction Ignore
    Set-Location $PSScriptRoot
}

Read-Host "Press Enter to exit"