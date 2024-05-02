cmake_minimum_required(VERSION 3.12)  # Указываем минимальную версию CMake

set(CMAKE_CXX_STANDARD 17)

project(MyProject)  # Устанавливаем имя проекта

set(SOURCES
    main.cpp
    factorial.cpp
)

# Добавляем исполняемый файл и указываем исходный файл
add_executable(my_program ${SOURCES})