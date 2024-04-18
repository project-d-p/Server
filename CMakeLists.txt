cmake_minimum_required(VERSION 3.0) # minimum version of cmake required to build this project
project(game_server) # name of the project

# set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the source files to compile
add_executable(game_service main.cpp srcs/server.cpp srcs/session.cpp)

# set the include directories

find_package(Boost 1.65.1 REQUIRED COMPONENTS system)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	target_link_libraries(game_service ${Boost_LIBRARIES})
endif()
