cmake_minimum_required(VERSION 3.0.0)
project(rvalue VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

add_executable(rvalue main.cpp)
add_executable(rvalue-ex1 rvalue-ex1.cpp)
add_executable(rvalue-ex2 rvalue-ex2.cpp)
add_executable(forward forward.cpp)
add_executable(recomendation recomendation.cpp)
add_executable(RVO RVO.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
