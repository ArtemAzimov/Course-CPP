cmake_minimum_required(VERSION 3.0.0)
project(hw VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(pair pair.cpp)
add_executable(queue queue.cpp)
add_executable(max max.cpp)
add_executable(max-variadic max-variadic.cpp)
add_executable(filter filter.cpp)

