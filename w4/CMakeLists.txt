cmake_minimum_required(VERSION 3.12)

project(set4 VERSION 1.0 LANGUAGES CXX)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)
set(CXX_EXTENSIONS Off)


add_executable(set4 src/main.cc)


target_include_directories(set4 PUBLIC
                         "${PROJECT_BIANRY_DIR}"
                         "${PROJECT_SOURCE_DIR}/src/26")


