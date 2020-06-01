cmake_minimum_required(VERSION 3.15)
project(VSPtrServer)

set(CMAKE_CXX_STANDARD 14)

add_executable(VSPtrServer main.cpp)
add_executable(VSPointer VSPtr.cpp)