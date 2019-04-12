//
// Created by Михаил on 2019-03-16.
//

#include <iostream>
#include <opencv2/imgproc.hpp>
#include "FrameHandler.h"
#include "GrayScaleFilter.h"
#include "EmphasizeFilter.h"
#include "TYPES.h"
void FrameHandler::setFrames(const cv::Mat& currentFrame_, const cv::Mat& nextFrame_) {
    currentFrame = currentFrame_;
    nextFrame    = nextFrame_;
    __clearResults();
}
void FrameHandler::setCurrentFrame(const cv::Mat& currentFrame_) {
    currentFrame = currentFrame_;
    __clearResults();
}
void FrameHandler::setNextFrame(const cv::Mat& nextFrame_) {
    nextFrame = nextFrame_;
    __clearResults();
}
void FrameHandler::__setup() {
    imageHandler = new ImageHandler;
    particleDistinguisher = new ParticleDistinguisher;
    positionTracker = new PositionTracker;
}
void FrameHandler::__process() {
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
    cv::Mat frame1gray, frame2gray;
    cv::cvtColor(currentFrame, frame1gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(nextFrame, frame2gray, cv::COLOR_BGR2GRAY);
    particleDistinguisher->setImage(frame1gray);
    particleDistinguisher->process();
    currentCenters = particleDistinguisher->getCenters();
    particleDistinguisher->setImage(frame2gray);
    particleDistinguisher->process();
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
void FrameHandler::reset() {
    __clearResults();
    imageHandler->reset();
    particleDistinguisher->reset();
    positionTracker->reset();
}
ImageHandler* FrameHandler::getImageHandler() {
    return imageHandler;
}
ParticleDistinguisher* FrameHandler::getParticleDistinguisher() {
    return particleDistinguisher;
}
PositionTracker* FrameHandler::getPositionTracker() {
    return positionTracker;
}
void FrameHandler::setParticleDistinguisher
(ParticleDistinguisher *particleDistinguisher_) {

    particleDistinguisher = particleDistinguisher_;
}
void FrameHandler::setImageHandler(ImageHandler *imageHandler_) {

    imageHandler = imageHandler_;
}
void FrameHandler::setPositionTracker(PositionTracker *positionTracker_) {

    positionTracker = positionTracker_;
}