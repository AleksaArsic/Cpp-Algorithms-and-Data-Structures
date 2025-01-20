# Project information
cmake_minimum_required(VERSION 3.15)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Queue_PriorityQueues VERSION 1.0.0)

set(INCLUDE_DIR include)
set(SOURCE_DIR src)

file(GLOB HEADERS ${INCLUDE_DIR}/*.hpp)
file(GLOB SRC_FILES ${SOURCE_DIR}/*.cpp)

include_directories(${INCLUDE_DIR})

set(SOURCES ./main.cpp
            ${SRC_FILES}
            ${HEADERS})

add_executable(Queue_PriorityQueues ${SOURCES})