cmake_minimum_required(VERSION 3.0.0)
project(gtest-ex VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_REQUIRED ON)

# set(CMAKE_CXX_COMPILER /usr/bin/clang++)
# set(CMAKE_GENERATOR Xcode)
# set(CONAN_DISABLE_CHECK_COMPILER ON)


# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
                "${CMAKE_BINARY_DIR}/conan.cmake"
                TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
# include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

conan_cmake_run(REQUIRES gtest/1.13.0 
        GENERATORS cmake cmake_multi cmake_find_package cmake_find_package_multi cmake_paths 
        BUILD missing
        # PROFILE clang12release 
        # SETTINGS compiler.version=12.0
        BUILD_TYPE Debug
        BASIC_SETUP CMAKE_TARGETS
        REMOTE conancenter
)

find_package(gtest REQUIRED)

add_executable(gtest-ex test.cpp)
target_link_libraries(gtest-ex CONAN_PKG::gtest)

add_executable(gtest-fix test-fixture.cpp)
target_link_libraries(gtest-fix CONAN_PKG::gtest)

add_executable(gtest-param test-param.cpp)
target_link_libraries(gtest-param CONAN_PKG::gtest)

add_executable(gtest-mock test-mock.cpp)
target_link_libraries(gtest-mock CONAN_PKG::gtest)
