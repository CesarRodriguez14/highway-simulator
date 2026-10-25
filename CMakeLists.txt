cmake_minimum_required(VERSION 3.14)

project(train-simulator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

option(ENABLE_COVERAGE "Enable code coverage" OFF)

if(ENABLE_COVERAGE)
    add_compile_options(--coverage  -O0 -g)
    add_link_options(--coverage)
endif()

add_subdirectory(src)
add_subdirectory(inc)
add_subdirectory(tests)