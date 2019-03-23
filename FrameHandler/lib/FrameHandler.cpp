//
// Created by Михаил on 2019-03-16.
//

#include <iostream>
#include "FrameHandler.h"
#include "BandWFilter.h"
#include "EmphasizeFilter.h"
#include "TYPES.h"
void FrameHandler::setFrames(cv::Mat currentFrame_, cv::Mat nextFrame_) {
    currentFrame = currentFrame_;
    nextFrame    = nextFrame_;
    __clearResults();
}
void FrameHandler::setCurrentFrame(cv::Mat currentFrame_) {
    currentFrame = currentFrame_;
    __clearResults();
}
void FrameHandler::setNextFrame(cv::Mat nextFrame_) {
    nextFrame = nextFrame_;
    __clearResults();
}
void FrameHandler::__setup() {
    __setupFilters();
    __setupParticleDistinguisher();
    __setupPositionTracker();
}
void FrameHandler::__setupFilters() {
    imageHandler = new ImageHandler;
    Filter* blackAndWhiteFilter = new BandWFilter;
    Filter* emphasizeFilter = new EmphasizeFilter;
    //@TODO organize filter setting
    imageHandler->addFilter(blackAndWhiteFilter);
    imageHandler->addFilter(emphasizeFilter);
}
void FrameHandler::__setupParticleDistinguisher() {
    particleDistinguisher = new ParticleDistinguisher;
    particleDistinguisher->setRadius(particleRadius);
}
void FrameHandler::__setupPositionTracker() {
    positionTracker =  new  PositionTracker;
    positionTracker->setRadius(particleRadius);
}
void FrameHandler::__process() {
    //@TODO Make filter parameters changeable. Probably through vector of params
    __filter();
    __distinguish();
    __track();
}
void FrameHandler::__filter() {
    // Filter first frame
    imageHandler->setImage(currentFrame);
    imageHandler->applyFilters();
    currentFrame = imageHandler->getImage();
    // Filter second frame

    imageHandler->setImage(nextFrame);
    imageHandler->applyFilters();
    nextFrame  = imageHandler->getImage();
}
void FrameHandler::__distinguish() {

    particleDistinguisher->setImage(currentFrame);
    currentCenters = particleDistinguisher->getCenters();

    particleDistinguisher->setImage(nextFrame);
    nextCenters = particleDistinguisher->getCenters();

}
void FrameHandler::__track() {
    positionTracker->setCenters(currentCenters, nextCenters);
    positionTracker->analyse();
    centerPositionChange = positionTracker->getUnitedCenters();
}
cv::Mat FrameHandler::getCurrentFrame() {
    return currentFrame;
}
cv::Mat FrameHandler::getNextFrame() {
    return nextFrame;
}
void FrameHandler::ProcessFrames() {
    __process();
}
FrameHandler::FrameHandler() {
    __setup();
}
std::vector<Coordinates> FrameHandler::getPositionChange() {
    return centerPositionChange;
}
void FrameHandler::__clearResults() {
    currentCenters.clear();
    nextCenters.clear();
    centerPositionChange.clear();
}
void FrameHandler::setParticleRadius(uint8_t particleRadius_) {
    particleRadius = particleRadius_;
    positionTracker->setRadius(particleRadius_);
    particleDistinguisher->setRadius(particleRadius_);
}
void FrameHandler::reset() {
    __clearResults();
    imageHandler->reset();
    particleDistinguisher->reset();
    positionTracker->reset();
}