cmake_minimum_required(VERSION 3.2)
project(untitled)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(untitled ${SOURCE_FILES} IContainer.h CContainer.h Ilist.h Hlist.h Ulist.hpp bin_tree.h)