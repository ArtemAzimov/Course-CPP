cmake_minimum_required(VERSION 3.0.0)
project(smart-pointers VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)

# add_executable(smart-pointers main.cpp)
# add_executable(uniqptr-ex uniqptr-ex.cpp)
# add_executable(uniqptr-ex2 uniqptr-ex2.cpp)
# add_executable(sharptr-ex sharptr-ex.cpp)
# add_executable(sharptr-ex-deleter sharptr-ex-deleter.cpp)
add_executable(weakptr-ex weakptr-ex.cxx)
# add_executable(uniqptr-ex uniqptr-ex.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
