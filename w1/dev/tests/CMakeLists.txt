
# add_test

function(add_exec target file)
    add_executable(${target} ${file})
    target_link_libraries(${target} PUBLIC Numbers)
    target_include_directories(${target} PUBLIC
                                "${PROJECT_BINARY_DIR}"
                                "${PROJECT_SOURCE_DIR}/numbers/inc")   
endfunction()

add_exec(ctor1 ctor1.cc)
add_exec(ctor2 ctor2.cc)
add_exec(ctor3 ctor3.cc)
add_exec(ctor4 ctor4.cc)
add_exec(insert-num insert-num.cc)
add_exec(ascp op_assign-cp.cc)
add_exec(asmv op_assign-mv.cc)



function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endfunction()

do_test(ctor1 "" "res")