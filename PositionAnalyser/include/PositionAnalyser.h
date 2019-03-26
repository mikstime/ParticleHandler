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
#include "TYPES.h"

class PositionAnalyser {
    //@TODO get rid of start and end
    uint16_t start, end;
    VideoReader* videoReader;
    FrameHandler* frameHandler;
    PositionLogger* positionLogger;
    PositionHandler* positionHandler;
    std::vector<Coordinates> currentPositions;
    void __setup();
    void __clearResults();
    void __process2Frames(uint16_t, uint16_t);
public:
    //Load video using VideoLoader
    void loadVideo(std::string);
    void savePositionList(std::string);
    void ProcessVideo();
    void setBorders(uint16_t, uint16_t);
    PositionAnalyser();
    void reset();
    //
    VideoReader* getVideoReader();
    FrameHandler* getFrameHandler();
    PositionLogger* getPositionLogger();
    PositionHandler* getPositionHandler();
};


#endif //FRAMEHANDLER_POSITIONANALYSER_H
