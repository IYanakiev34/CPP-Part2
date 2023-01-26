cmake_minimum_required(VERSION 3.12)

project(set8 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(set8 src/main.cc)

target_compile_options(set8 PRIVATE -Wall -Werror -O2 -pedantic)

target_include_directories(set8 PRIVATE 
                    "${PROJECT_BINARY_DIR}/"
                    "${PROJECT_SOURCE_DIR}/src")
    
