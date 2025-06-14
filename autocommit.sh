#!/bin/bash.exe
export PATH="/c/Program Files/Git/bin:$PATH"

        # Переход в корень репозитория
        cd "$(git rev-parse --show-toplevel)" || exit 1

        # Получаем список добавленных файлов
        staged_files=$(git diff --name-only --cached)

        # Для каждого файла
        for file in $staged_files; do
            filename=$(basename "$file")
            if [[ $file == *.cpp ]]; then
                git commit -m "$filename" -- "$file"
            else
                git commit -m "Trash" -- "$file"
            fi
            git push origin MIPT
        done