cmake_minimum_required(VERSION 3.1)
project(P2)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SOURCES "*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(p2 ${SOURCES})
target_compile_options(p2 PRIVATE -Wall)
