cmake_minimum_required(VERSION 3.12)
project(MyProject)

# Включение Conan в CMake
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Добавление исходных файлов проекта
add_executable(MyProject src/main.cpp)

# Линковка с установленными пакетами Conan
target_link_libraries(MyProject ${CONAN_LIBS})