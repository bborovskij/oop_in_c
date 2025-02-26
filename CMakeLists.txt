cmake_minimum_required(VERSION 3.29)
project(oop_vehicle C)

set(CMAKE_C_STANDARD 11)

file(GLOB all_sources src/*.c)

add_executable(oop_vehicle main.c ${all_sources})
target_include_directories(oop_vehicle PRIVATE include)
