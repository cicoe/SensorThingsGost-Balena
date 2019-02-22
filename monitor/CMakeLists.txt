cmake_minimum_required(VERSION 3.3)
project(ST_Beagle)


set(SOURCE_FILES
        common_dht_read.h
        common_dht_read.c
        bbb_mmio.h
        bbb_mmio.c
        bbb_dht_read.h
        bbb_dht_read.c
        main.c)

add_executable(sensorapp main.c)
