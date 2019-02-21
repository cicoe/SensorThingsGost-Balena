cmake_minimum_required(VERSION 3.13)
project(DH11 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(DH11
        bbb_dht_read.c
        bbb_dht_read.h
        bbb_mmio.c
        bbb_mmio.h
        common_dht_read.h
        common_dht_read.c
        main.c)
