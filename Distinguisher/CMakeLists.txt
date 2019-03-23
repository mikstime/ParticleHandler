cmake_minimum_required(VERSION 3.13)


project(distinguisher)

find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/ParticleDistinguisher.h lib/ParticleDistinguisher.cpp)
add_library(distinguisher STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(distinguisher ${OpenCV_LIBS})