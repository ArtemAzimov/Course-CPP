cmake_minimum_required(VERSION 3.12)
project(package-code)

set(CMAKE_CXX_STANDARD 11)

add_library(package-lib SHARED package-code.cpp)
