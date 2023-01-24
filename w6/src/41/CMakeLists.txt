cmake_minimum_required(VERSION 3.12)

add_library(41 data.cc
               fill.cc
               random.cc
               store.cc)

target_precompile_headers(41 PRIVATE 41.ih)