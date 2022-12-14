cmake_minimum_required(VERSION 3.12)

project(set4 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)
set(CXX_EXTENSIONS Off)

add_subdirectory(src/26)
add_subdirectory(src/27)
add_subdirectory(src/29)
add_subdirectory(src/30)

add_executable(set4 src/main.cc src/derived_factory.cc src/freeBasePointers.cc)

target_link_libraries(set4 PUBLIC 26)
target_link_libraries(set4 PUBLIC 27)
target_link_libraries(set4 PUBLIC 29)
target_link_libraries(set4 PUBLIC 30)

target_include_directories(set4 PUBLIC
                         "${PROJECT_BIANRY_DIR}"
                         "${PROJECT_SOURCE_DIR}/src/26"
                         "${PROJECT_SOURCE_DIR}/src/29"
                         "${PROJECT_SOURCE_DIR}/src/30")

target_precompile_headers(set4 PRIVATE src/main.ih)



