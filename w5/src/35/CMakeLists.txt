cmake_minimum_required(VERSION 3.12)

add_library(35 
        strings.cc
        strings1.cc
        strings2.cc
        at.cc
        add.cc)


target_precompile_headers(35 PRIVATE strings.ih)