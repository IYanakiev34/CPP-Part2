cmake_minimum_required(VERSION 3.12)

add_library(CONS 
            ctor.cc
            dtor.cc
            mov-ctor.cc
            joinThread.cc
            startThread.cc
            pollLines.cc)

target_link_libraries(CONS PRIVATE STORAGE)
