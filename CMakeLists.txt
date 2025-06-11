cmake_minimum_required(VERSION 3.31)
project(ClionProjectsStepik.cpp)

# Автоматическая перезагрузка при изменении структуры
set(CMAKE_CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR})
if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.31)
    cmake_policy(SET CMP0146 NEW)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Рекурсивно находим все .cpp файлы с автообновлением
file(GLOB_RECURSE ALL_SOURCE_FILES
        LIST_DIRECTORIES false
        CONFIGURE_DEPENDS  # Это обеспечивает автообновление
        "*.cpp"
)

# Создаем файл-триггер для перезагрузки
configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
        ${CMAKE_BINARY_DIR}/CMakeLists.txt.copy
)

foreach(SOURCE_FILE IN LISTS ALL_SOURCE_FILES)
    # Получаем относительный путь файла
    file(RELATIVE_PATH REL_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${SOURCE_FILE})

    # Удаляем расширение .cpp
    string(REGEX REPLACE "\\.cpp$" "" EXECUTABLE_PATH ${REL_PATH})

    # Формируем безопасное имя цели
    string(REPLACE "." "_" SAFE_TARGET_NAME ${REL_PATH})
    string(REPLACE "/" "_" SAFE_TARGET_NAME ${SAFE_TARGET_NAME})
    string(REPLACE " " "_" SAFE_TARGET_NAME ${SAFE_TARGET_NAME})
    string(REGEX REPLACE "\\.cpp$" "" SAFE_TARGET_NAME ${SAFE_TARGET_NAME})

    # Создаем исполняемый файл
    if(NOT TARGET ${SAFE_TARGET_NAME})
        add_executable(${SAFE_TARGET_NAME} ${SOURCE_FILE})

        # Устанавливаем желаемое имя выходного файла
        set_target_properties(${SAFE_TARGET_NAME} PROPERTIES
                OUTPUT_NAME "${EXECUTABLE_PATH}"
        )

        message(STATUS "Added target: ${SAFE_TARGET_NAME} for ${SOURCE_FILE}")
    endif()
endforeach()

# Дополнительная проверка для новых файлов
list(LENGTH ALL_SOURCE_FILES NUM_SOURCE_FILES)
message(STATUS "Total source files detected: ${NUM_SOURCE_FILES}")