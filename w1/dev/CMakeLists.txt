# Cmake minimum version
cmake_minimum_required(VERSION 3.12)

# Defining the project
project(test VERSION 1.0 LANGUAGES CXX)

# Setting the cpp standard
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)
# Adding the library directory
add_subdirectory(numbers)

set(ExecutableName set1)

# creating the executable
add_executable(${ExecutableName} main.cpp)

# Adding the compiler flags
target_compile_options(${ExecutableName} PRIVATE -Wall -Werror)

# Linking the library with the executable
target_link_libraries(${ExecutableName} PUBLIC Numbers)

# Specifying the include directory of the library
target_include_directories(${ExecutableName} PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/numbers/inc")
