cmake_minimum_required(VERSION 3.29)
project(lab_2)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)

add_executable(lab_2
        include/number.h
        src/number.cpp
        src/main.cpp)
