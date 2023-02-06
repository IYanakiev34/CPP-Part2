cmake_minimum_required(VERSION 3.12)

add_library(BLOCKQUEUE 
            ctor.cc
            empty.cc
            front.cc
            pop.cc
            push.cc)

target_precompile_headers(BLOCKQUEUE PRIVATE BlockQueue.ih)
