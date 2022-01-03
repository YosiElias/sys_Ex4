cmake_minimum_required(VERSION 3.21)
project(code C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_executable(code
        graph.c
        graph.h
        main.c)
