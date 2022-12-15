cmake_minimum_required(VERSION 3.12)

project(Set5 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)
add_executable(set5 src/main.cc src/printset.cc src/scanset.cc)


target_include_directories(set5 PRIVATE
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/src")

target_precompile_headers(set5 PRIVATE src/main.ih)