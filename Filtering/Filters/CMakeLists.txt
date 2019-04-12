cmake_minimum_required(VERSION 3.13)

project(filters)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)

include_directories(include)
set(SOURCE_LIB include/Filter.h
        include/EmphasizeFilter.h lib/EmphasizeFilter.cpp
        include/GreyScaleFilter.h lib/GreyScaleFilter.cpp)

add_library(filters STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(filters ${OpenCV_LIBS})