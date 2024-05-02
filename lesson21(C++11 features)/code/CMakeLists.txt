cmake_minimum_required(VERSION 3.0.0)
project(cppeleven VERSION 0.1.0)

include(CTest)
enable_testing()

set(_WIN32)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppeleven main.cpp)
add_executable(auto auto.cpp)
add_executable(forloop forloop.cpp)
add_executable(function function.cpp)
add_executable(observable observable.cpp)
# add_executable(factorial constexpr.cpp)
add_executable(chrono chrono.cpp)
add_executable(chrono2 chrono2.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
