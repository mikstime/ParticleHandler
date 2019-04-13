//
// Created by Михаил on 2019-03-18.
//

#ifndef FRAMEHANDLER_POSITIONANALYSER_H
#define FRAMEHANDLER_POSITIONANALYSER_H


#include "VideoReader.h"
#include "FrameHandler.h"
#include "PositionLogger.h"
#include "PositionHandler.h"
#include <iostream>
#include "TYPES.h"
#include <string>
#include <list>
namespace mbtsky {
    using namespace mbtsky;
    class PositionAnalyser {
        //*********************************************************************
        // videoReader is used for reading concrete frames
        //*********************************************************************
        VideoReader *videoReader;

        //*********************************************************************
        // frame handler is used for getting position change between two frames
        //*********************************************************************
        FrameHandler *frameHandler;

        //*********************************************************************
        // PositionHandler is used for combining all positions together
        //*********************************************************************
        PositionHandler *positionHandler;

        //*********************************************************************
        // PositionLogger is used for saving the result
        //*********************************************************************
        PositionLogger *positionLogger;

        //*********************************************************************
        // currentPosition is  used for storing positions that are not combined
        //*********************************************************************
        std::vector<Coordinates> currentPositions;

        //*********************************************************************
        // __setup
        //  setup modules
        //*********************************************************************
        void __setup();

        //*********************************************************************
        // __clearResults
        // remove all stored data
        //*********************************************************************
        void __clearResults();

        //*********************************************************************
        // __process2Frames
        // track particles in 2 frames
        //*********************************************************************
        void __process2Frames(uint16_t, uint16_t);

    public:

        //*********************************************************************
        // loadVideo
        //Load video using VideoLoader
        //*********************************************************************
        void loadVideo(std::string);

        //*********************************************************************
        // savePositionList
        // Save positions by path
        //*********************************************************************
        void savePositionList(std::string);

        //*********************************************************************
        // ProcessVideo
        // Process chosen frames in video
        //*********************************************************************
        void ProcessVideo();

        //*********************************************************************
        // Default constructor
        //*********************************************************************
        PositionAnalyser();

        //*********************************************************************
        // Copy constructor
        //*********************************************************************
        PositionAnalyser(PositionAnalyser&);

        //*********************************************************************
        // reset
        // remove all stored data and reset all used modules
        //*********************************************************************
        void reset();

        //*********************************************************************
        // getVideoReader
        // @result pointer to videoReader
        //*********************************************************************
        VideoReader *getVideoReader() {
            return videoReader;
        };

        //*********************************************************************
        // setVideoReader
        //*********************************************************************
        void setVideoReader(VideoReader *videoReader_) {
            videoReader = videoReader_;
        };

        //*********************************************************************
        // getFrameHandler
        // @result pointer to frameHandler
        //*********************************************************************
        FrameHandler *getFrameHandler() {
            return frameHandler;
        };

        //*********************************************************************
        // setFrameHandler
        //*********************************************************************
        void setFrameHandler(FrameHandler *frameHandler_) {
            frameHandler  = frameHandler_;
        };

        //*********************************************************************
        // getPositionLogger
        // @result  pointer to positionLogger
        //*********************************************************************
        PositionLogger *getPositionLogger() {
            return positionLogger;
        };

        //*********************************************************************
        //  setPositionLogger
        //*********************************************************************
        void setPositionLogger(PositionLogger *positionLogger_) {
            positionLogger = positionLogger_;
        };

        //*********************************************************************
        // getPositionHandler
        // @result pointer to positionHandler
        //*********************************************************************
        PositionHandler *getPositionHandler() {
            return positionHandler;
        };

        //*********************************************************************
        // setPositionHandler
        //*********************************************************************
        void setPositionHandler(PositionHandler * positionHandler_) {
            positionHandler = positionHandler_;
        };
    };
}

#endif //FRAMEHANDLER_POSITIONANALYSER_H
