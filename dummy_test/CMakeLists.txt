cmake_minimum_required(VERSION 3.0) # minimum version of cmake required to build this project
project(dummy_client) # name of the project

# set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# set the source files to compile
add_executable(dummy_client dummy_client.cpp
	../proto_build/message.pb.cc ../proto_build/movement.pb.cc ../proto_build/player_position.pb.cc
	../proto_build/state.pb.cc ../proto_build/vector.pb.cc)

# set the include directories
find_package(Boost 1.65.1 REQUIRED COMPONENTS system)
if(Boost_FOUND)
	include_directories(${Boost_INCLUDE_DIRS})
	target_link_libraries(dummy_client ${Boost_LIBRARIES})
endif()

find_package(Protobuf REQUIRED)  # Find the protobuf package
if(PROTOBUF_FOUND)
    include_directories(${PROTOBUF_INCLUDE_DIRS})
    target_link_libraries(dummy_client ${PROTOBUF_LIBRARIES})  # Link protobuf libraries
endif()

# set the protocol buffer files path to compile
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../proto_build)

# Add a custom target for cleaning object files including all subdirectories
add_custom_target(clean-objs
    COMMAND ${CMAKE_COMMAND} -E echo "Removing object files in all subdirectories..."
    COMMAND find ${CMAKE_BINARY_DIR}/CMakeFiles -type f -name '*.o' -exec rm {} +
    COMMAND ${CMAKE_COMMAND} -E echo "Object files removed."
)
