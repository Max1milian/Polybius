cmake_minimum_required(VERSION 3.14)
project(Polybius
	LANGUAGES CXX
	VERSION 0.0.1
	DESCRIPTION "A 2D psychedelic Horror Shot-em Up!"
	HOMEPAGE_URL "https://github.com/Max1milian/Polybius")

include(cmake/dependencies.cmake)

if(MSVC)
	add_compile_options(\W3 \WX)
elseif(GNU)
	add_compile_options(-Wall -Werror -Wextra -pedantic-errors -fanalyzer)
else()
	add_compile_options(-Wall -Werror -Wextra -pedantic-errors)
endif(MSVC)

# This is the main part:
set(SOURCES src/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp fmt::fmt)
