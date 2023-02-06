cmake_minimum_required(VERSION 3.12)

add_library(FILEFINDER 
        check_ext.cc
        get_sources_dir_rec.cc)

target_precompile_headers(FILEFINDER PRIVATE FileFinder.ih)
