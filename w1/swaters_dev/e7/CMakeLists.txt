cmake_minimum_required(VERSION 3.21)
project(e7)

set(CMAKE_CXX_STANDARD 20)

add_executable(e7 main.cpp lib.cpp lib.h)
target_compile_options(e7 PRIVATE -Wextra -Wpedantic --std=c++20 -Wall -Werror)