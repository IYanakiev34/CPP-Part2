cmake_minimum_required(VERSION 3.24)
project(31)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(31
        dtor.cc
        Fork.h
        fork.ih
        forkmet.cc
        waitforchild.cc)
