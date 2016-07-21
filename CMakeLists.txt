cmake_minimum_required (VERSION 2.8)
project (HTTP_SERVER CXX)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(src
main.cpp
TCPServer.cpp
ThreadPool.cpp
Worker.cpp
TCPServer.h
ThreadPool.h
Worker.h)
add_executable(final ${src})
TARGET_LINK_LIBRARIES(final pthread)