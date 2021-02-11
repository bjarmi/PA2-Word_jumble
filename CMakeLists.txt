cmake_minimum_required(VERSION 3.17)
project(PA2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(PA2 main.cpp List.cpp List.h Scramble.cpp Scramble.h)