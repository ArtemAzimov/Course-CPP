cmake_minimum_required(VERSION 3.0.0)
project(hw21 VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(hw21 
    main-Duplicates.cpp
    DuplicatesDestroyer.cpp
    DuplicatesDestroyer.hpp
    getHash.hpp
    )

# g++ -std=c++17 main-Duplicates.cpp DuplicatesDestroyer.cpp -o gppVar

# gcc -lstdc++ -std=c++17 main-Duplicates.cpp DuplicatesDestroyer.cpp -o gccVar

# clang++ -std=c++17 main-Duplicates.cpp DuplicatesDestroyer.cpp -o clangVar