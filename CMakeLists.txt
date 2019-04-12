cmake_minimum_required(VERSION 3.13)
project(ParticleHandler)


find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 17)
include_directories(${CMAKE_SOURCE_DIR})
include_directories(Filtering/include)
include_directories(Filtering/Filters/include)
include_directories(ParticleRecognizer/include)
include_directories(Tracker/include)
include_directories(Readers/include)
include_directories(Readers/Path/include)
include_directories(FrameHandler/include)
include_directories(PositionAnalyser/include)
include_directories(Loader/include)
###
add_subdirectory(Filtering)
add_subdirectory(Filtering/Filters)
add_subdirectory(ParticleRecognizer)
add_subdirectory(Tracker)
add_subdirectory(Readers)
add_subdirectory(Readers/Path)
add_subdirectory(FrameHandler)
add_subdirectory(PositionAnalyser)
add_subdirectory(Loader)
add_executable(ParticleHandler main.cpp)

include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(ParticleHandler ${OpenCV_LIBS}
        Path
        filtering
        filters
        tracker
        readers
        frameHandler
        positionAnalyser
        loaders
        Recognizer)