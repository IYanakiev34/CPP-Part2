cmake_minimum_required(VERSION 3.12)

project (set2 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)
set(CXX_EXTENSIONS Off)

add_subdirectory(src/ex1)
add_subdirectory(src/ex2)
add_subdirectory(src/ex3)
add_subdirectory(src/ex5)

add_executable(set2 src/main.cc)

target_link_libraries(set2 PUBLIC Ex1)
target_link_libraries(set2 PUBLIC Ex3)
target_link_libraries(set2 PUBLIC Ex5)

target_include_directories(set2 PUBLIC
                        "${PROJECT_BINARY_DIR}"
                        "{PROJECT_SOURCE_DIR}/ex1"
                        "${PROJETC_SOURCE_DIR}/ex2"
                        "{PROJECT_SOURCE_DIR}/ex3"
                        "{PROJECT_SOURCE_DIR}/ex5")   


