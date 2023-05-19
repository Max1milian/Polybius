cmake_minimum_required(VERSION 3.14)
project(Polybius
	LANGUAGES CXX
	VERSION 0.0.1
	DESCRIPTION "A 2D psychedelic Horror Shot-em Up!"
	HOMEPAGE_URL "https://github.com/Max1milian/Polybius")

include(cmake/CPM.cmake)
CPMAddPackage("gh:SFML/SFML#2.6.x")
CPMAddPackage("gh:fmtlib/fmt#9.1.0")
CPMAddPackage("gh:erincatto/box2d#v2.4.1")

if(MSVC)
	add_compile_options(\W3 \WX)
elseif(GNU)
	add_compile_options(-Wall -Werror -Wextra -pedantic-errors -fanalyzer)
else()
	add_compile_options(-Wall -Werror -Wextra -pedantic-errors)
endif(MSVC)

# This is the main part:
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp) #error gets fixed with future refactoring
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_link_libraries(${PROJECT_NAME} PUBLIC 
	sfml-system 
	sfml-window 
	sfml-graphics 
	sfml-audio 
	fmt::fmt
	box2d
)
