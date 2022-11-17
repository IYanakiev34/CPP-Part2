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
            lib/add_l.cc
            lib/add_op.cc
            lib/add_r.cc
            lib/add_bin-l.cc
            lib/add_bin-r.cc
            lib/subtract-op.cc
            lib/subtract_l.cc
            lib/subtract_r.cc
            lib/subtract_bin-l.cc
            lib/subtract_bin-r.cc
            lib/mult-op.cc
            lib/mult_l.cc
            lib/mult_r.cc
            lib/mult_bin-l.cc
            lib/mult_bin-r.cc
            lib/div-op.cc
            lib/div_l.cc
            lib/div_r.cc
            lib/div_bin-l.cc
            lib/div_bin-r.cc
            lib/eq.cc
            )   
# add the precompiled headers
target_precompile_headers(Numbers PRIVATE inc/numbers.ih)