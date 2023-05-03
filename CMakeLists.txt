cmake_minimum_required(VERSION 3.14)
project(Polybius
	VERSION 0.0.1
	LANGUAGES CXX
	DESCRIPTION "2D psychedelic Horro Shotem-Up"
	HOMEPAGE_URL "https://github.com/Max1milian/Polybius")

if(MSVC)
	add_compile_options(\W3 \WX)
else()
	add_compile_options(-Wall -Wextra -Werror -pedantic-errors -fanalyzer)
endif(MSVC)

include(cmake/dependencies.cmake)
# This is the main part:
set(SOURCES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)
