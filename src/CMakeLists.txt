cmake_minimum_required(VERSION 3.20)

project(multithread_assignment C)

set(CMAKE_C_FLAGS "-pthread")

add_executable(multithread_assignment main.c)