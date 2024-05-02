cmake_minimum_required(VERSION 3.12)
project(myapp)

set(CMAKE_CXX_STANDARD 11)
#set(CONAN_DISABLE_CHECK_COMPILER)
#set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(KEEP_RPATHS)

find_package(package-lib REQUIRED)

add_executable(myapp main.cpp)
target_link_libraries(myapp package-lib::package-lib)
