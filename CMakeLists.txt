cmake_minimum_required(VERSION 3.31)
project(CLionProjectsStepik_cpp)

set(CMAKE_CXX_STANDARD 20)

# Создаем список всех исходных файлов
set(SOURCE_FILES
        1.2_ex_1.cpp
        1.2_ex_2.cpp
        1.3_ex_1.cpp
        1.3_ex_2.cpp
        1.3_ex_3.cpp
        1.3_ex_4.cpp
        1.3_ex_14.cpp
        1.3_ex_5.cpp
        1.3_ex_6.cpp
        1.3_ex_7.cpp
        1.3_ex_8.cpp
        1.3_ex_9.cpp
        1.3_ex_10.cpp
        1.3_ex_11.cpp
        1.3_ex_12.cpp
        1.3_ex_13.cpp
        1.4_ex_1.cpp
        1.4_ex_2.cpp
        1.4_ex_3.cpp
        1.4_ex_4.cpp
        1.4_ex_5.cpp
        1.4_ex_6.cpp
        1.4_ex_7.cpp
        1.4_ex_8.cpp
        1.4_ex_9.cpp
        1.4_ex_10.cpp
        1.4_ex_11.cpp
        1.4_ex_12.cpp
        1.4_ex_13.cpp
        1.4_ex_14.cpp
)
set(counter 1)
foreach(SOURCE_FILE ${SOURCE_FILES})
    # Получаем имя файла без расширения
    get_filename_component(FILE_NAME ${SOURCE_FILE} NAME_WE)
    # Создаем исполняемый файл с уникальным номером
    add_executable(exe_${counter}_${FILE_NAME} ${SOURCE_FILE})
    math(EXPR counter "${counter} + 1")
endforeach()


# Создаем отдельный исполняемый файл для main.cpp
add_executable(main main.cpp)

