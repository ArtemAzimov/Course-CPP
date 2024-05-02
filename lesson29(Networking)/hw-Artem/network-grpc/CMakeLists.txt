cmake_minimum_required(VERSION 3.12)

project(simplenet)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Command to generate C++ gRPC files.
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)

if(MSVC)
    set(protoc build_tools/protoc.exe)
    set(grpc_plugin build_tools/grpc_cpp_plugin.exe)
else()
    set(protoc build_tools/protoc)
    set(grpc_plugin build_tools/grpc_cpp_plugin)
endif()

set(hw_protos ${PROJECT_NAME}.proto)
set(hw_proto_srcs "${CMAKE_CURRENT_BINARY_DIR}/generated/${PROJECT_NAME}.pb.cc")
set(hw_proto_hdrs "${CMAKE_CURRENT_BINARY_DIR}/generated/${PROJECT_NAME}.pb.h")
set(hw_grpc_srcs "${CMAKE_CURRENT_BINARY_DIR}/generated/${PROJECT_NAME}.grpc.pb.cc")
set(hw_grpc_hdrs "${CMAKE_CURRENT_BINARY_DIR}/generated/${PROJECT_NAME}.grpc.pb.h")
add_custom_command(
    OUTPUT "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
    COMMAND build_tools/protoc.exe
    ARGS --grpc_out "${CMAKE_CURRENT_BINARY_DIR}/generated"
         --cpp_out "${CMAKE_CURRENT_BINARY_DIR}/generated"
         -I "../protos"
         --plugin=protoc-gen-grpc="build_tools/grpc_cpp_plugin.exe"
         ${hw_protos}
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/../protos/${hw_protos}
    COMMENT "Invoking protoc to generate gRPC C++ files."
    )

# Custom target for generating C++ gRPC files that other targets can depend on.
add_custom_target(generate_grpc_files
    DEPENDS "${hw_proto_srcs}" "${hw_proto_hdrs}" "${hw_grpc_srcs}" "${hw_grpc_hdrs}"
    )

# Client executable.
add_executable(client)

target_include_directories(client
    PRIVATE src
            ${CMAKE_CURRENT_BINARY_DIR}/generated
    )

target_sources(client
    PRIVATE src/client.cpp
            ${hw_proto_srcs}
            ${hw_grpc_srcs}
    )

target_link_libraries(client
    PRIVATE CONAN_PKG::grpc
    )

add_dependencies(client generate_grpc_files)

# Server executable.
add_executable(server)

target_include_directories(server
    PRIVATE src
            ${CMAKE_CURRENT_BINARY_DIR}/generated
    )

target_sources(server
    PRIVATE src/server.cpp src/Logger.cpp
            ${hw_proto_srcs}
            ${hw_grpc_srcs}
    )

target_link_libraries(server
    PRIVATE CONAN_PKG::grpc
    )

add_dependencies(server generate_grpc_files)
