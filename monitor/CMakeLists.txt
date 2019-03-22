cmake_minimum_required(VERSION 3.7)
project(monitor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lcurl")

include_directories(.)
#include_directories(/usr/include/x86_64-linux-gnu/curl)
#include_directories(DHT11)
#include_directories(IO)
add_subdirectory(IO)
add_subdirectory(DHT11)

add_executable(monitor main.c)
target_link_libraries(monitor STinterface DHT11 curl )
