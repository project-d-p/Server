cmake_minimum_required(VERSION 3.0)
project(game_server)

find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-g)

option(protobuf_MODULE_COMPATIBLE TRUE)
find_package(Protobuf CONFIG REQUIRED)
message(STATUS "Using protobuf ${Protobuf_VERSION}")

set(_PROTOBUF_LIBPROTOBUF protobuf::libprotobuf)
set(_REFLECTION gRPC::grpc++_reflection)
if(CMAKE_CROSSCOMPILING)
find_program(_PROTOBUF_PROTOC protoc)
else()
set(_PROTOBUF_PROTOC $<TARGET_FILE:protobuf::protoc>)
endif()

# Find gRPC installation
# Looks for gRPCConfig.cmake file installed by gRPC's cmake installation.
find_package(gRPC CONFIG REQUIRED)
message(STATUS "Using gRPC ${gRPC_VERSION}")

set(_GRPC_GRPCPP gRPC::grpc++)
if(CMAKE_CROSSCOMPILING)
find_program(_GRPC_CPP_PLUGIN_EXECUTABLE grpc_cpp_plugin)
else()
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
endif()

MESSAGE(STATUS "_Reflection: ${_REFLECTION}")
MESSAGE(STATUS "_GRPC: ${_GRPC_GRPCPP}")
MESSAGE(STATUS "_PROTO: ${_PROTOBUF_LIBPROTOBUF}")

set(PROTO_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/message.proto"
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/movement.proto"
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/player_position.proto"
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/attach.proto"
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/state.proto"
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/vector.proto"
    "${CMAKE_CURRENT_SOURCE_DIR}/proto/grpc_match.proto"
)

set(GENERATED_DIR "${CMAKE_CURRENT_SOURCE_DIR}/generated")
file(MAKE_DIRECTORY ${GENERATED_DIR})

# Loop through each proto file
foreach(PROTO_FILE IN LISTS PROTO_FILES)
    get_filename_component(FILE_WE ${PROTO_FILE} NAME_WE)

    # Define output source and header files for protobuf and gRPC
    set(PROTO_SRC "${GENERATED_DIR}/${FILE_WE}.pb.cc")
    set(PROTO_HDR "${GENERATED_DIR}/${FILE_WE}.pb.h")
    set(GRPC_SRC "${GENERATED_DIR}/${FILE_WE}.grpc.pb.cc")
    set(GRPC_HDR "${GENERATED_DIR}/${FILE_WE}.grpc.pb.h")

    add_custom_command(
        OUTPUT "${PROTO_SRC}" "${PROTO_HDR}" "${GRPC_SRC}" "${GRPC_HDR}"
        COMMAND ${_PROTOBUF_PROTOC}
            ARGS --grpc_out "${GENERATED_DIR}"
            --cpp_out "${GENERATED_DIR}"
            -I "${CMAKE_CURRENT_SOURCE_DIR}/proto"
            --plugin=protoc-gen-grpc="${_GRPC_CPP_PLUGIN_EXECUTABLE}"
            "${PROTO_FILE}"
        DEPENDS "${PROTO_FILE}"
    )

    list(APPEND GENERATED_SOURCES "${PROTO_SRC}" "${GRPC_SRC}")
    list(APPEND GENERATED_HEADERS "${PROTO_HDR}" "${GRPC_HDR}")
endforeach()

add_library(hw_grpc_proto
    ${GENERATED_SOURCES}
    ${GENERATED_HEADERS}
)

target_include_directories(hw_grpc_proto
    PUBLIC
    ${GENERATED_DIR}
)

target_link_libraries(hw_grpc_proto
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
)

add_executable(game_server
main.cpp srcs/server.cpp srcs/session.cpp srcs/protobuf_mannager.cpp
srcs/prototype.cpp srcs/prototype_factory.cpp srcs/movement_prototype.cpp
srcs/channel.cpp srcs/call_data.cpp srcs/call_data_create_channel.cpp
srcs/call_data_attach_player.cpp
)

target_link_libraries(game_server
    hw_grpc_proto
    absl::flags
    absl::flags_parse
    ${_REFLECTION}
    ${_GRPC_GRPCPP}
    ${_PROTOBUF_LIBPROTOBUF}
)
