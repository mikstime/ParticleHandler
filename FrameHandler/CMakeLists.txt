cmake_minimum_required(VERSION 3.13)


project(frameHandler)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/FrameHandler.h lib/FrameHandler.cpp)
add_library(frameHandler STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(frameHandler ${OpenCV_LIBS})