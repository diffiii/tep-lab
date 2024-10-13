cmake_minimum_required(VERSION 3.29)
project(lab1)

set(CMAKE_CXX_STANDARD 98)

include_directories(include)

add_executable(lab1
        src/main.cpp
        include/const.h
        include/utils.h
        src/utils.cpp
        include/allocations.h
        src/allocations.cpp
        include/ctable.h
        src/ctable.cpp)
