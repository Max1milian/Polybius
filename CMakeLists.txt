cmake_minimum_required(VERSION 3.14)
project(Polybius
        VERSION 0.0.1
        HOMEPAGE_URL https://github.com/Max1imilian/Polybius.git
        DESCRIPTION "A 2D psychedelic horror Shoot-em Up! Made with C++ and SFML."
        LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(cmake/deps.cmake)
include(cmake/cflags.cmake)
include(cmake/cppcheck.cmake)

add_subdirectory(src)
add_subdirectory(Polybius)
