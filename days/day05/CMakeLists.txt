cmake_minimum_required(VERSION 3.25)
project(day05)

set(CMAKE_CXX_STANDARD 23)

add_executable(day05 main.cpp src/Crate.h src/DataParser.cpp src/DataParser.h src/Crane.cpp src/Crane.h src/Stack.cpp src/Stack.h)
