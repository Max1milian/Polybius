# raylib
find_package(raylib CONFIG REQUIRED)

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.0
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

#fmt
find_package(fmt CONFIG REQUIRED)
