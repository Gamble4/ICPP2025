
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#disable in command-line with -DCOMPILE_FLAGS_ON=NO
set(COMPILE_FLAGS_ON YES CACHE BOOL "")

if (COMPILE_FLAGS_ON)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

project(E1)
add_library(E1lib src/E1.cpp src/E1.hpp)
add_executable(test.out test.cpp)
target_link_libraries(test.out E1lib)