# add the sources of the library
add_library(Numbers 
            lib/ctor-cp.cc
            lib/ctor-mv.cc
            lib/ctor1.cc
            lib/ctor2.cc
            lib/ctor3.cc
            lib/ctor4.cc
            lib/swap.cc
            lib/op_assign-cp.cc
            lib/op_assign-mv.cc
            lib/insert-num.cc
            )   
# add the precompiled headers
target_precompile_headers(Numbers PRIVATE inc/numbers.ih)