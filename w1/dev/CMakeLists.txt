# Cmake minimum version
cmake_minimum_required(VERSION 3.12)

# Defining the project
project(test VERSION 1.0 LANGUAGES CXX)

# Setting the cpp standard
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

# Adding the library directory
add_subdirectory(numbers)
# Add subdirectory for enums
add_subdirectory(enums)

# Set the name of the main executable
set(ExecutableName set1)

# creating the executable
add_executable(${ExecutableName} main.cpp)
# Adding the compiler flags
target_compile_options(${ExecutableName} PRIVATE -Wall -Werror)


# Add the library for the main
add_library(Main copy_file.cc namespaces.cc)

# Create the precompiled headers for the main library
target_precompile_headers(Main PRIVATE main.ih)

# Linking the library with the executable
target_link_libraries(Main PUBLIC Numbers)

# Specifying the include directory of the numbers library
target_include_directories(Main PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/numbers/inc")


# Add library enums
target_link_libraries(Main PUBLIC Enums)
target_include_directories(Main PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}/enums/inc")

# Link the main library to the main executable
target_link_libraries(${ExecutableName} PUBLIC Main)
target_include_directories(${ExecutableName} PUBLIC
                            "${PROJECT_BINARY_DIR}"
                            "${PROJECT_SOURCE_DIR}")       
