cmake_minimum_required(VERSION 3.6)
project(thread)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(include)

set(SOURCE_FILES
        include/Executor.h
        Executor.cpp
        )

add_executable(thread ${SOURCE_FILES})
