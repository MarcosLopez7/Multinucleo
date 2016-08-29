cmake_minimum_required(VERSION 3.5)
project(CpuSuma)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main2.c.cpp)
add_executable(CpuSuma ${SOURCE_FILES})