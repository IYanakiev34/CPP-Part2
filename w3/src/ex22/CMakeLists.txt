add_library(Ex22 base_hello.cc derived_hello.cc)

target_precompile_headers(Ex22 PUBLIC ex22.ih)