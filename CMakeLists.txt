cmake_minimum_required(VERSION 3.7)
project(hw3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Tree.cpp Tree.h Node.cpp Node.h)
add_executable(hw3 ${SOURCE_FILES})