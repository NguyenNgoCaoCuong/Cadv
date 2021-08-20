cmake_minimum_required(VERSION 3.16)

project(CAdvanced C)
option(GPROF_FLAG "Bổ sung khóa để sử dụng với gprof" OFF)
option(USE_IGRAPH "Sử dụng igraph (xem hướng dẫn trong igraph.cmd)" OFF)
option(BUILD_DEMO "Biên dịch các ví dụ minh họa" OFF)
option(MY_TEST "Biên dịch các bai test của tôi" OFF)


set(CMAKE_C_STANDARD 99)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

if (GPROF_FLAG)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pg")
endif (GPROF_FLAG)

add_subdirectory(DebugPrintf)
add_subdirectory(libfdr)
add_subdirectory(btree)
add_subdirectory(c-vector)
include_directories(btree/inc c-vector igraph)
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/btree)
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/libfdr)
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/c-vector)

if (EXISTS "${CMAKE_SOURCE_DIR}/binaries/libigraph.a")
  set(USE_IGRAPH ON)
endif ()

if (USE_IGRAPH)
  add_library(igraph STATIC IMPORTED)
  set_target_properties(igraph PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/binaries/libigraph.a)
  set(IGRAPH_LIBS igraph m)
endif (USE_IGRAPH)

if (BUILD_DEMO)
  add_subdirectory(demo)
endif (BUILD_DEMO)

if(MY_TEST)
  add_subdirectory(test)
endif(MY_TEST)

# tham khao huong dan cmakelists.txt



