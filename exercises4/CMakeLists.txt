
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#disable in command-line with -DCOMPILE_FLAGS_ON=NO
set(COMPILE_FLAGS_ON YES CACHE BOOL "")

if (COMPILE_FLAGS_ON)
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

project(D1)
add_library(D1lib src/D1.cpp src/D1.hpp)
add_executable(D1.out D1main.cpp)
target_link_libraries(D1.out D1lib)