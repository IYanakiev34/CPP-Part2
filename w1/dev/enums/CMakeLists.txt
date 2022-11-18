add_library(Enums lib/show.cc)

target_precompile_headers(Enums PRIVATE inc/msg.ih)