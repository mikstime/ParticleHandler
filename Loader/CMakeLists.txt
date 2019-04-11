cmake_minimum_required(VERSION 3.13)

project(loaders)
set(CMAKE_CXX_STANDARD 17)
find_package(OpenCV REQUIRED)
include_directories(include)

set(SOURCE_LIB include/json.hpp include/Loader.h lib/Loader.cpp include/LoadableObjectBase.h lib/LoadableObjectBase.cpp
        )

add_library(loaders STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(loaders ${OpenCV_LIBS})