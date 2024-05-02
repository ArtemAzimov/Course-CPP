cmake_minimum_required(VERSION 3.0.0)
project(hw VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 14)

# add_executable(hw 1_even_vector.cpp)
add_executable(hw TextEditor_v2/TextEditor.cpp TextEditor_v2/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
