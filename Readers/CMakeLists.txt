cmake_minimum_required(VERSION 3.13)

project(readers)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/FileReader.h lib/FileReader.cpp
               include/ImageReader.h lib/ImageReader.cpp
               include/VideoReader.h lib/VideoReader.cpp
               include/VideoReaderSettinger.h lib/VideoReaderSettinger.cpp)

add_library(readers STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(readers ${OpenCV_LIBS})