cmake_minimum_required(VERSION 4.0.0)
include(cmake/cflags.cmake)
project(
  Polybius
  DESCRIPTION "A 2D psychedelic Horror shoot-em up. Made with C++ and SFML"
  VERSION 0.0.1
  LANGUAGES CXX)

add_subdirectory(src)
add_subdirectory(Polybius)
