cmake_minimum_required(VERSION 3.12)

project(set8 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)
set(CXX_EXTENSIONS Off)

add_executable(set8 src/main.cc)

add_subdirectory(src/57)
add_subdirectory(src/63)
add_subdirectory(src/queue)
add_subdirectory(src/CompileFlag)
add_subdirectory(src/CompileWorker)

target_compile_options(set8 PRIVATE -Wall -Werror -O2 -pedantic -lpthread)

target_include_directories(set8 PRIVATE 
                    "${PROJECT_BINARY_DIR}/"
                    "${PROJECT_SOURCE_DIR}/src"
                    "${PROJECT_SOURCE_DIR}/src/57/"
                    "${PROJECT_SOURCE_DIR}/src/63/"
                    "${PROJECT_SOURCE_DIR}/src/queue")

target_link_libraries(set8 PRIVATE SEMAPHORE FILEFINDER BLOCKQUEUE FLAG WORKER)

target_precompile_headers(set8 PRIVATE src/main.ih)
    
