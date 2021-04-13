cmake_minimum_required(VERSION 3.20)

project(multithread_assignment C)

# include_directories()
set(CMAKE_C_FLAGS "-pthread -std=c99 -Wall -lm -g")
# https://cmake.org/cmake/help/latest/manual/cmake-generator-expressions.7.html#manual:cmake-generator-expressions(7)
add_executable(multithread_assignment main.c parser.c Image_struct/image_struct.c)
