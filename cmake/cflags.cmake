# Check if the compiler is MSVC
if(MSVC)
  # Enable all compiler warnings for MSVC
  add_compile_options(
    /W4 # Enable many warnings
    /Wall # Enable all warnings
    /WX # Treat warnings as errors
  )
elseif(CMAKE_COMPILER_IS_GNUCXX)
  # Enable all compiler warnings for GCC
  add_compile_options(
    -Wall # Enable basic warnings
    -Wextra # Enable extra warnings
    -Wpedantic # Enable strict ANSI C++ warnings
    -Werror # Treat warnings as errors
  )
endif()
