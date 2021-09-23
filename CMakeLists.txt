# CMakeList.txt : CMake project for checkers, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("checkers")

# Add source to this project's executable.
add_executable (
	checkers 
	"checkers.cpp"
	"checkers.h"
	"sources/Model/Model.h"
	"sources/Model/Model.cpp"
	
	
	"sources/Model/Board.h"
	"sources/Model/Board.cpp"
	
	 
	"sources/Controller/Controller.h" 
	"sources/Controller/Controller.cpp" 
	"sources/View/View.h" 
	"sources/View/View.cpp" "sources/Model/Player.h" "sources/Model/Player.cpp")

target_link_libraries(checkers ${CMAKE_SOURCE_DIR}/libraries/sfml-graphics.lib)
target_link_libraries(checkers ${CMAKE_SOURCE_DIR}/libraries/sfml-audio.lib)
target_link_libraries(checkers ${CMAKE_SOURCE_DIR}/libraries/sfml-network.lib)
target_link_libraries(checkers ${CMAKE_SOURCE_DIR}/libraries/sfml-system.lib)
target_link_libraries(checkers ${CMAKE_SOURCE_DIR}/libraries/sfml-window.lib)

include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET checkers PROPERTY CXX_STANDARD 17)
set_property(TARGET checkers PROPERTY CXX_STANDARD_REQUIERD ON)

# TODO: Add tests and install targets if needed.
