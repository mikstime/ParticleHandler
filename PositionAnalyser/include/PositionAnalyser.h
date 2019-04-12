//
// Created by Михаил on 2019-03-18.
//

#ifndef FRAMEHANDLER_POSITIONANALYSER_H
#define FRAMEHANDLER_POSITIONANALYSER_H


#include "FrameHandler.h"
#include "VideoReader.h"
#include "PositionLogger.h"
#include "PositionHandler.h"
#include <string>
#include <list>
#include "TYPES.h"
namespace mbtsky {
    using namespace mbtsky;
    class PositionAnalyser {
        VideoReader *videoReader;
        FrameHandler *frameHandler;
        PositionLogger *positionLogger;
        PositionHandler *positionHandler;
        std::vector<Coordinates> currentPositions;

        void __setup();

        void __clearResults();

        void __process2Frames(uint16_t, uint16_t);

    public:
        //Load video using VideoLoader
        void loadVideo(std::string);

        void savePositionList(std::string);

        void ProcessVideo();

        PositionAnalyser();

        void reset();

        //
        VideoReader *getVideoReader();

        void setVideoReader(VideoReader *);

        FrameHandler *getFrameHandler();

        void setFrameHandler(FrameHandler *);

        PositionLogger *getPositionLogger();

        void setPositionLogger(PositionLogger *);

        PositionHandler *getPositionHandler();

        void setPositionHandler(PositionHandler *);
    };
}

#endif //FRAMEHANDLER_POSITIONANALYSER_H
