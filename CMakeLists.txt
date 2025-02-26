cmake_minimum_required(VERSION 3.29)
project(oop_vehicle C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_DEBUG "-O0 -ggdb")

add_executable(oop_vehicle main.c
        vehicle.c
        vehicle.h
        car.c
        car.h
        bike.h
        bike.c)
