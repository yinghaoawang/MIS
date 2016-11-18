cmake_minimum_required(VERSION 3.6)
project(network)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(include)
include_directories(../socket/include)

set(SOURCE_FILES
        include/ByteBuffer.h
        include/TCPConnection.h
        TCPConnection.cpp
        ByteBuffer.cpp
        TCPServerChannel.cpp include/TCPServerChannel.h Message.cpp include/Message.h AsyncSessionHandler.cpp AsyncSessionHandler.h)
#target_link_libraries(network socket)

add_executable(network ${SOURCE_FILES})
