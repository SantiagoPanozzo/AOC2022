cmake_minimum_required(VERSION 3.25)
project(day06)

set(CMAKE_CXX_STANDARD 23)

add_executable(day06 main.cpp src/DataAnalizer.cpp src/DataAnalizer.h test/ExampleTest.cpp test/ExampleTest.h)
