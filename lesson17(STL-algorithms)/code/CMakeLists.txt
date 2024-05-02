cmake_minimum_required(VERSION 3.0.0)
project(algorithms VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)

# add_executable(algorithms main.cpp)
# add_executable(policy policy.cpp)
# add_executable(measure measure.cpp)
# add_executable(any_of any_of.cpp)
# add_executable(negate negate.cpp)
# add_executable(functor functor.cpp)
# add_executable(example-alg example-alg.cpp)
# add_executable(transform transform.cpp)
add_executable(accumulate accumulate.cpp)

