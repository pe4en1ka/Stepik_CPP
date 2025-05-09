cmake_minimum_required(VERSION 3.31)
project(CLionProjectsStepik_cpp)

set(CMAKE_CXX_STANDARD 20)

# Получаем список всех .cpp файлов в директории проекта
file(GLOB ALL_SOURCE_FILES "*.cpp")

# Создаем пустой список для файлов, исключая main.cpp
set(SOURCE_FILES "")

# Перебираем все найденные файлы
foreach(FILE ${ALL_SOURCE_FILES})
    get_filename_component(FILENAME ${FILE} NAME)
    # Добавляем в список все файлы, кроме main.cpp
    if(NOT ${FILENAME} STREQUAL "main.cpp")
        list(APPEND SOURCE_FILES ${FILE})
    endif()
endforeach()

# Нумеруем и создаем исполняемые файлы
set(counter 1)
foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    add_executable(exe_${counter}_${FILE_NAME} ${SOURCE_FILE})
    math(EXPR counter "${counter} + 1")
endforeach()

# Отдельно добавляем main.cpp
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
    add_executable(main main.cpp
            1.5_ex_2.cpp
            1.5_ex_3.cpp
            1.5_ex_4.cpp
            1.5_ex_5.cpp
            1.5_ex_6.cpp
            1.5_ex_7.cpp
            1.5_ex_8.cpp)
endif()


