cmake_minimum_required(VERSION 3.28)

project(
    reductions
    VERSION 1.0
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)
