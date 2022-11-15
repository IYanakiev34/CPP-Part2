cmake_minimum_required(VERSION 3.12)

project(test VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(test main.cpp)

target_compile_options(test PRIVATE -Wall -Werror)