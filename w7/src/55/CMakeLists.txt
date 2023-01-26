cmake_minimum_required(VERSION 3.12)

add_library(CONS
            ctor.cc
            mov-ctor.cc
            dtor.cc
            poll.cc
            start.cc)

target_link_libraries(CONS PRIVATE STORAGE)
target_precompile_headers(CONS PRIVATE consThr.ih)