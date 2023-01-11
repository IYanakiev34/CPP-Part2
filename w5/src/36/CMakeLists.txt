cmake_minimum_required (VERSION 3.12)

add_library(SmartStrings 
    smart_str.cc
    smart_str1.cc
    smart_str2.cc
    at.cc
    add.cc)

target_precompile_headers(SmartStrings PRIVATE smart_str.ih)