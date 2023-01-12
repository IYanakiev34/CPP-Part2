cmake_minimum_required(VERSION 3.12)

project(set6 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(set6 src/main.cc)

add_subdirectory(src/41)
add_subdirectory(src/47)

target_link_libraries(set6 PRIVATE 41 IOTA)

target_include_directories(set6 PRIVATE 
                "${PROJECT_BINARY_DIR}"
                "${PROJECT_SOURCE_DIR}/src"
                "${PROJECT_SOURCE_DIR}/src/41/"
                "${PROJECT_SOURCE_DIR}/src/47/")

