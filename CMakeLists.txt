cmake_minimum_required(VERSION 3.6)
project(MISVM)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(network)
add_subdirectory(socket)
add_subdirectory(thread)
include_directories(include)

set(SOURCE_FILES src/AddMulParser.cpp src/AssignParser.cpp src/Cache.cpp src/Data.cpp src/JmpglteParser.cpp
        src/JmpParser.cpp src/JmpznzParser.cpp src/Label.cpp src/LabelParser.cpp src/main.cpp src/OperationFactory.cpp
        src/OutParser.cpp src/Parser.cpp src/ParserFactory.cpp src/SleepParser.cpp src/StrCharParser.cpp src/SubDivParser.cpp
        src/Token.cpp src/Variable.cpp src/VarParser.cpp

        include/AddMulParser.h include/AssignParser.h include/Cache.h include/Data.h include/IDataHandler.h
        include/JmpglteParser.h include/JmpParser.h include/JmpznzParser.h include/Label.h include/LabelParser.h
        include/Label.h include/LabelParser.h include/Operation.h include/OperationFactory.h include/OutParser.h
        include/Parser.h include/ParserFactory.h include/SleepParser.h include/StrCharParser.h include/SubDivParser.h
        include/Token.h include/Util.h include/Variable.h include/VarParser.h include/VM.h
        )

add_executable(MISVM ${SOURCE_FILES})
