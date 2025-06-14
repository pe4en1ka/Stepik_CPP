#!/bin/bash
echo "=== STARTING AUTOCOMMIT WITH DIAGNOSTICS ==="
echo "Current directory: $(pwd)"

# Явно указываем путь к Git
export PATH="/c/Program Files/Git/bin:$PATH"
echo "Git version: $(git --version)"

# Переходим в корень репозитория
REPO_ROOT=$(git rev-parse --show-toplevel)
echo "Repo root: $REPO_ROOT"
cd "$REPO_ROOT" || exit 1

# Полная диагностика состояния репозитория
echo ""
echo "===== GIT STATUS ====="
git status
echo ""

echo "===== STAGED FILES (git diff --cached --name-only) ====="
staged_files=$(git diff --cached --name-only)
echo "$staged_files"
echo ""

echo "===== STAGED FILES (git ls-files) ====="
git ls-files --cached --modified --others --exclude-standard
echo ""

echo "===== ALL CHANGED FILES ====="
git diff --name-only
echo ""

echo "===== TRACKED FILES ====="
git ls-files
echo ""

# Принудительно добавляем ВСЕ изменения
echo "Force adding all changes..."
git add -A --force

# Снова получаем список staged files
staged_files=$(git diff --cached --name-only)
echo "Staged files after force add:"
echo "$staged_files"
echo ""

# Если нет файлов - выводим расширенную диагностику
if [ -z "$staged_files" ]; then
    echo "!!! NO STAGED FILES DETECTED !!!"
    echo "Possible reasons:"
    echo "1. Files are ignored by .gitignore"
    echo "2. Repository is in detached HEAD state"
    echo "3. Permissions issues"
    echo "4. Path problems in Windows"

    echo ""
    echo "===== .GITIGNORE CONTENT ====="
    cat .gitignore 2>/dev/null || echo "No .gitignore file"

    echo ""
    echo "===== FILE SYSTEM CHECK ====="
    echo "Top 10 files in repo:"
    find . -type f | head -n 10

    exit 1
fi

# Коммитим каждый файл отдельно
while IFS= read -r file; do
    # Проверяем существование файла
    if [ ! -e "$file" ]; then
        echo "File not found: $file"
        continue
    fi

    filename=$(basename "$file")

    # Для .cpp файлов
    if [[ $file == *.cpp ]]; then
        echo "Committing .cpp file: $filename"
        git commit -m "$filename" -- "$file"
    else
        # Для остальных файлов
        echo "Committing non-cpp file: $filename"
        git commit -m "Trash" -- "$file"
    fi

    # Пушим изменения
    git push origin MIPT -f
done <<< "$staged_files"

echo "=== FINISHED ==="
sleep 5