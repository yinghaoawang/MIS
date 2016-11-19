cmake_minimum_required(VERSION 3.6)
project(socket)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(include)

set(SOURCE_FILES
        include/common.h
        include/includes.h
        include/TCPSocket.h
        include/TCPServerSocket.h
        include/UDPSocket.h
        include/UDPClientSocket.h
        include/UDPServerSocket.h
        TCPSocket.cpp
        TCPServerSocket.cpp
        UDPClientSocket.cpp
        UDPSocket.cpp
        UDPServerSocket.cpp
        )

add_executable(socket ${SOURCE_FILES})
