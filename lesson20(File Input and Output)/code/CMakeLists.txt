cmake_minimum_required(VERSION 3.0.0)
project(work-with-file VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# add_executable(work-with-file simple.cpp)
# add_executable(work-with-file read-write.cpp)
# add_executable(exceptions exceptions.cpp)
add_executable(filesystem filedir.cpp)
