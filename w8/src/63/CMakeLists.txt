cmake_minimum_required(VERSION 3.12)

add_library(FILEFINDER 
        file_ctor.cc
        delete_instance.cc
        get_instance.cc
        get_sources_dir.cc
        instance.cc
        check_ext.cc
        get_sources_dir_rec.cc)

target_precompile_headers(FILEFINDER PRIVATE FileFinder.ih)