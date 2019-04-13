cmake_minimum_required(VERSION 3.13)


project(objectManager)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/ObjectManager.h lib/ObjectManager.cpp)
add_library(objectManager STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(objectManager ${OpenCV_LIBS})