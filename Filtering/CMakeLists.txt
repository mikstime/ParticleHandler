cmake_minimum_required(VERSION 3.13)

#include_directories(${CMAKE_SOURCE_DIR}/Filtering/Filters/include)
project(filtering)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/FilterApplier.h lib/FilterApplier.cpp
               include/FilterApplierSettinger.h lib/FilterApplierSettinger.cpp
               include/ImageHandler.h lib/ImageHandler.cpp)
add_library(filtering STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(filtering ${OpenCV_LIBS})