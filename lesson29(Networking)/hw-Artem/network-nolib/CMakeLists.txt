cmake_minimum_required(VERSION 3.12)
project(networkHW)

set(CMAKE_CXX_STANDARD 14)

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

# Линкинг библиотеки
link_libraries(Ws2_32.lib)

add_executable(server1 server1.cpp)
add_executable(client1 client1.cpp)

# target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})