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
class FrameHandler {
    ImageHandler* imageHandler;
    PositionTracker* positionTracker;
    ParticleDistinguisher* particleDistinguisher;

    cv::Mat currentFrame, nextFrame;

    Coordinates  currentCenters, nextCenters;
    std::vector<Coordinates> centerPositionChange;

    void __process();
    void __filter();
    void __distinguish();
    void __track();
    void __setup();
    void __clearResults();
public:
    void setFrames(const cv::Mat&, const cv::Mat&);
    void setCurrentFrame(const cv::Mat&);
    void setNextFrame(const cv::Mat&);
    cv::Mat getCurrentFrame();
    cv::Mat getNextFrame();
    std::vector<Coordinates> getPositionChange();
    void ProcessFrames();
    FrameHandler();
    void reset();
    //
    void setImageHandler(ImageHandler*);
    ImageHandler* getImageHandler();
    void setParticleDistinguisher(ParticleDistinguisher*);
    ParticleDistinguisher* getParticleDistinguisher();
    void setPositionTracker(PositionTracker*);
    PositionTracker* getPositionTracker();

};


#endif //PARTICLEDISTINGUISHER_FRAMEHANDLER_H
