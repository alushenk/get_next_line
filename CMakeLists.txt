cmake_minimum_required(VERSION 3.5)
project(get_next_line)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c get_next_line.h get_next_line.c)
add_executable(get_next_line ${SOURCE_FILES} main.c get_next_line.h get_next_line.c)