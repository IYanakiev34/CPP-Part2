cmake_minimum_required(VERSION 3.12)

project(set7 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

add_executable(set7 src/main.cc )

add_subdirectory(src/52)
add_subdirectory(src/54)

target_include_directories(set7 PRIVATE
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/src"
                            "${PROJECT_SOURCE_DIR}/src/52/"
                            "${PROJECT_SOURCE_DIR}/src/54/"
                            "${PROJECT_SOURCE_DIR}/src/55/")


target_link_libraries(set7 PRIVATE HANDLER STORAGE)
target_precompile_headers(set7 PRIVATE src/main.ih)