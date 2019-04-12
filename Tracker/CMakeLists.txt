cmake_minimum_required(VERSION 3.13)


project(tracker)
find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/PositionTracker.h lib/PoisitoinTracker.cpp
               include/PositionHandler.h lib/PositionHandler.cpp
               include/PositionLogger.h lib/PositionLogger.cpp
        )
add_library(tracker STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(tracker ${OpenCV_LIBS})