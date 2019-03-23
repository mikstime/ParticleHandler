cmake_minimum_required(VERSION 3.13)


project(positionAnalyser)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/PositionAnalyser.h lib/PositionAnalyser.cpp)
add_library(positionAnalyser STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(positionAnalyser ${OpenCV_LIBS})