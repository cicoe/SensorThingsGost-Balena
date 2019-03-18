cmake_minimum_required(VERSION 3.10)
project(monitor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_library(DHT11 STATIC bbb_dht_read.c bbb_mmio.c common_dht_read.c)
target_include_directories(DHT11 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
