cmake_minimum_required(VERSION 3.13)

project(Path)

set(SOURCE_LIB include/Path.h lib/Path.cpp)
add_library(Path STATIC ${SOURCE_LIB} ../../TYPES.h)