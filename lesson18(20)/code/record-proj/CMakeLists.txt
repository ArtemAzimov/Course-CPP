cmake_minimum_required(VERSION 3.0.0)
project(notebook VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

add_executable(notebook 
    main.cpp
    notebook.cpp
    record.cpp
)

