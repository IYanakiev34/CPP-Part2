cmake_minimum_required(VERSION 3.12)

project(set3 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)
set(CXX_EXTENSIONS On)

add_subdirectory(src/ex18)

add_executable(set3 src/main.cc)

target_link_libraries(set3 PUBLIC Ex18)

target_include_directories(set3 PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        "${PROJECT_SOURCE_DIR}/ex18"
                        "${PROJECT_SOURCE_DIR}")   
