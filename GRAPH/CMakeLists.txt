cmake_minimum_required(VERSION 3.1)
project(GRAPH)

set(CMAKE_CXX_STANDARD 98)

add_subdirectory(libfdr)
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/libfdr)
include_directories(MyIgraph/include)
file(GLOB SOURCE "MyIgraph/src/*.c")
add_executable(GRAPH ${SOURCE}   test.c)
target_link_libraries(GRAPH fdr)

