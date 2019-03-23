//
// Created by Михаил on 2019-03-18.
//

#ifndef FRAMEHANDLER_POSITIONANALYSER_H
#define FRAMEHANDLER_POSITIONANALYSER_H


#include "FrameHandler.h"
#include "VideoReader.h"
#include "PositionHandler.h"
#include <string>
#include <list>
typedef std::vector<cv::Point> Points;

class PositionAnalyser {
    uint16_t start, end;
    uint8_t particleRadius;
    VideoReader* videoReader;
    FrameHandler* frameHandler;
    PositionLogger* positionLogger;
    PositionHandler* positionHandler;
    std::vector<Points> currentPositions;
    void __setup();
    void __setupVideoReader();
    void __setupFrameHandler();
    void __setupPositionLogger();
    void __setupPositionHandler();
    void __clearResults();
    void __process2Frames(uint16_t, uint16_t);
public:
    //Load video using VideoLoader
    void setParticleRadius(uint8_t);
    void loadVideo(std::string);
    void savePositionList(std::string);
    void ProcessVideo();
    void setBorders(uint16_t, uint16_t);
    PositionAnalyser();
    void reset();
};


#endif //FRAMEHANDLER_POSITIONANALYSER_H
