//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_FRAMEHANDLER_H
#define PARTICLEDISTINGUISHER_FRAMEHANDLER_H


#include "ImageHandler.h"
#include "ParticleDistinguisher.h"
#include "PositionTracker.h"
#include "TYPES.h"
typedef std::vector<double> ParamList;
//@TODO Add method .Clear()
class FrameHandler {
    ImageHandler* imageHandler;
    ParticleDistinguisher* particleDistinguisher;
    PositionTracker* positionTracker;
    cv::Mat currentFrame, nextFrame;
    Coordinates  currentCenters, nextCenters;
    //@TODO reorganize parametrs
    //@TODO and the way of passing it to handlers
    uint8_t particleRadius;
    std::vector<Coordinates> centerPositionChange;
    void __process();
    void __filter();
    void __distinguish();
    void __track();
    void __setup();
    void __setupFilters();
    void __setupParticleDistinguisher();
    void __setupPositionTracker();
    void __clearResults();
public:
    //@TODO change particle parametres on the go
    void setFrames(cv::Mat, cv::Mat);
    void setParticleRadius(uint8_t);
    void setCurrentFrame(cv::Mat);
    void setNextFrame(cv::Mat);
    cv::Mat getCurrentFrame();
    cv::Mat getNextFrame();
    std::vector<Coordinates> getPositionChange();
    void ProcessFrames();
    void setParams(ParamList);
    FrameHandler();
    void reset();
};


#endif //PARTICLEDISTINGUISHER_FRAMEHANDLER_H
