function(macros target)
        target_compile_definitions(${target} PUBLIC ASSETS="${CMAKE_ROOT}/assets/")
endfunction()
