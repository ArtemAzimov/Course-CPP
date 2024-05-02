cmake_minimum_required(VERSION 3.0.0)
project(thread VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(thread thread1.cpp)
add_executable(mutex1 mutex1.cpp)
add_executable(deadlock-decision deadlock-decision.cpp)
add_executable(convar1 convar1.cpp)
add_executable(convar2 convar2.cpp)
add_executable(convar3 convar3.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
