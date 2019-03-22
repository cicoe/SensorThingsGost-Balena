cmake_minimum_required(VERSION 3.7)
project(monitor)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcurl")
include_directories(.)
#include_directories(/usr/include/x86_64-linux-gnu/curl)
add_library(STinterface STATIC cJSON.c ST_interface.c)
target_include_directories(STinterface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})



