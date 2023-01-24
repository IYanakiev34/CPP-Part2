cmake_minimum_required(VERSION 3.12)

add_library(HANDLER shift.cc)

target_precompile_headers(HANDLER PRIVATE handler.ih)