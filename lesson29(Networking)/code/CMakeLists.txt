cmake_minimum_required(VERSION 3.0.0)
project(network VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 14)

include(CTest)
enable_testing()

add_executable(client1 client1.cpp)
add_executable(server1 server1.cpp)
add_executable(server-thread server-thread.cpp)

