cmake_minimum_required(VERSION 3.31)
project(CourseProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Жестко фиксируем выходной каталог
set(BIN_OUTPUT_DIR "${CMAKE_BINARY_DIR}/bin")
file(MAKE_DIRECTORY ${BIN_OUTPUT_DIR})

# Устанавливаем выходные каталоги
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BIN_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# Функция для добавления упражнений
function(add_exercise source_file)
    # Получаем имя файла без расширения
    get_filename_component(exercise_name ${source_file} NAME_WE)

    # Создаем уникальное имя цели
    string(REPLACE "." "-" target_name "${exercise_name}")
    string(REPLACE "/" "_" target_name "${target_name}")

    # Добавляем исполняемый файл
    add_executable(${target_name} ${source_file})

    # Жестко устанавливаем выходной путь
    set_target_properties(${target_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${BIN_OUTPUT_DIR}"
            OUTPUT_NAME "${exercise_name}"
    )

    # Дополнительная защита от создания файлов в корне
    set_target_properties(${target_name} PROPERTIES
            VS_DEBUGGER_WORKING_DIRECTORY "${BIN_OUTPUT_DIR}"
    )
endfunction()

# Поиск всех исходных файлов в проекте
file(GLOB_RECURSE ALL_SOURCES
        LIST_DIRECTORIES false
        "1/*/1-*_ex_*.cpp"
        "2/*/2-*_ex_*.cpp"
        "3/*/3-*_ex_*.cpp"
        "4/*/4-*_ex_*.cpp"
        "5/*/5-*_ex_*.cpp"
)

# Обработка каждого файла
foreach(source_file ${ALL_SOURCES})
    add_exercise(${source_file})
endforeach()

# Цель для удаления EXE-файлов из корня (вызывается вручную)
add_custom_target(clean_exes
        COMMAND ${CMAKE_COMMAND} -E remove -f "${CMAKE_CURRENT_SOURCE_DIR}/*.exe"
        COMMENT "Removing EXE files from root directory"
)