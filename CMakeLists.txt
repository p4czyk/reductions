cmake_minimum_required(VERSION 3.28)

project(
    reductions
    VERSION 1.0
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

find_package(Boost
    1.74
    REQUIRED
)

add_subdirectory(src)
add_subdirectory(test)
