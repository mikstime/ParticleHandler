cmake_minimum_required(VERSION 3.13)


project(Recognizer)

find_package(OpenCV REQUIRED)

set(SOURCE_LIB include/ParticleRecognizer.h lib/ParticleRecognizer.cpp
        )
add_library(Recognizer STATIC ${SOURCE_LIB})

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(Recognizer ${OpenCV_LIBS})