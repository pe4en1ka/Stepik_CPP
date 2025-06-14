import os
import subprocess
import sys
import locale

# Определяем кодировку консоли
ENCODING = locale.getpreferredencoding()

# Явное указание пути к Git
GIT_PATH = r"C:\Program Files\Git\bin\git.exe"

# Путь к корню репозитория (где находится .git)
REPO_ROOT = r"C:\Users\tmame\MIPT_cpp"

def log(message):
    # Кодируем сообщение в кодировку консоли
    try:
        print(message.encode(ENCODING, errors='replace').decode(ENCODING))
    except:
        print(message)

def run_command(command, cwd=None):
    """Выполняет команду и возвращает результат"""
    if cwd is None:
        cwd = REPO_ROOT

    log(f"Выполняю команду: {' '.join(command)} в {cwd}")

    try:
        result = subprocess.run(
            command,
            cwd=cwd,
            capture_output=True,
            text=True,
            encoding=ENCODING,  # Используем системную кодировку
            errors='replace'
        )

        if result.stdout:
            log(f"Результат:\n{result.stdout}")
        if result.stderr:
            log(f"Ошибки:\n{result.stderr}")

        return result
    except Exception as e:
        log(f"Ошибка выполнения команды: {str(e)}")
        return None

def main():
    try:
        # Проверяем доступность Git
        version_result = run_command([GIT_PATH, "--version"])
        if not version_result or version_result.returncode != 0:
            log("Git не доступен! Проверьте путь к Git.")
            return

        # Проверяем существование репозитория
        git_dir = os.path.join(REPO_ROOT, ".git")
        if not os.path.exists(git_dir):
            log(f"Ошибка: {REPO_ROOT} не является репозиторием Git (папка .git не найдена)")
            return

        log(f"Рабочая директория репозитория: {REPO_ROOT}")

        # 1. Добавляем все изменения в репозитории
        add_result = run_command([GIT_PATH, "add", "--all", "."])
        if not add_result or add_result.returncode != 0:
            log("Ошибка при добавлении файлов в Git")
            return

        # 2. Получаем список добавленных файлов
        staged_files = run_command([GIT_PATH, "diff", "--name-only", "--cached"])
        if not staged_files or not staged_files.stdout.strip():
            log("Нет изменений для коммита")
            return

        files = staged_files.stdout.splitlines()
        log(f"Найдено файлов для коммита: {len(files)}")

        # 3. Коммитим каждый файл отдельно
        for file in files:
            if not file.strip():
                continue

            # Полный путь к файлу
            full_path = os.path.join(REPO_ROOT, file)

            # Проверяем существование файла
            if not os.path.exists(full_path):
                log(f"Файл не существует: {full_path}")
                continue

            filename = os.path.basename(file)

            # Определяем сообщение коммита
            if file.endswith(".cpp"):
                commit_message = filename
                file_type = "CPP"
            else:
                commit_message = "Trash"
                file_type = "Other"

            log(f"Коммит файла ({file_type}): {filename}")

            # Коммитим файл
            commit_result = run_command([
                GIT_PATH, "commit",
                "-m", commit_message,
                "--", file
            ])

            # Если коммит успешен - пушим
            if commit_result and commit_result.returncode == 0:
                log("Коммит успешен. Отправляю изменения...")
                push_result = run_command([GIT_PATH, "push", "origin", "HEAD", "-f"])
            else:
                log(f"Ошибка при коммите файла {filename}")

    except Exception as e:
        log(f"Критическая ошибка: {str(e)}")
        import traceback
        log(traceback.format_exc())
        sys.exit(1)

if __name__ == "__main__":
    main()
    log("Скрипт завершен")
    input("Нажмите Enter для выхода...")