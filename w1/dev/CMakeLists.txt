# Cmake minimum version
cmake_minimum_required(VERSION 3.12)

# Defining the project
project(test VERSION 1.0 LANGUAGES CXX)

# Setting the cpp standard
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

# Adding the library directory
add_subdirectory(numbers)

# creating the executable
add_executable(test main.cpp)

# Adding the compiler flags
target_compile_options(test PRIVATE -Wall -Werror)

# Linking the library with the executable
target_link_libraries(test PUBLIC Numbers)

# Specifying the include directory of the library
target_include_directories(test PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/numbers/include")