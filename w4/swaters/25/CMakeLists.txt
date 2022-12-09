cmake_minimum_required(VERSION 3.21)
project(25)

set(CMAKE_CXX_STANDARD 20)

add_executable(25 main.cpp Base.cpp Base.h Derived.cpp Derived.h Message.cpp Message.h)
