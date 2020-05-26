cmake_minimum_required(VERSION 3.15)
project(VSPointer)

set(CMAKE_CXX_STANDARD 14)

SET(CMAKE_CXX_FLAGS -pthread)

add_library(VSPointer SHARED library.cpp library.h)