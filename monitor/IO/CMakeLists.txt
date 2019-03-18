cmake_minimum_required(VERSION 3.7)
project(monitor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_library(STinterface STATIC cJSON.c ST_interface.c)
target_include_directories(STinterface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

