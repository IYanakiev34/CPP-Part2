cmake_minimum_required(VERSION 3.12)

project(set6 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(set6 
            src/main.cc 
            src/read.cc 
            src/writeNames.cc 
            src/writeNrs.cc
            src/create_ind.cc
            src/sort_names.cc
            src/sort_number.cc)

add_subdirectory(src/41)
add_subdirectory(src/47)
add_subdirectory(src/44)

target_link_libraries(set6 PRIVATE 41 IOTA STUDENT)

target_include_directories(set6 PRIVATE 
                "${PROJECT_BINARY_DIR}"
                "${PROJECT_SOURCE_DIR}/src"
                "${PROJECT_SOURCE_DIR}/src/41/"
                "${PROJECT_SOURCE_DIR}/src/47/"
                "${PROJECT_SOURCE_DIR}/src/44/")

