cmake_minimum_required(VERSION 3.12)

add_library(SEMAPHORE
            ctor.cc
            notify_all.cc
            notify.cc
            wait.cc)