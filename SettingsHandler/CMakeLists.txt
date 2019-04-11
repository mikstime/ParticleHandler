cmake_minimum_required(VERSION 3.13)

project(settingsHandler)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/SettingsHandler.h
               lib/SettingsHandler.cpp
               lib/Settinger.cpp
               include/Settinger.h)
add_library(settingsHandler STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(settingsHandler ${OpenCV_LIBS})