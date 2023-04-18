cmake_minimum_required(VERSION 3.10)

project(demo)

set(CMAKE_C_FLAGS)

include_directories(include)

aux_source_directory(src SRC_LIST)

add_executable(demo ${SRC_LIST})


