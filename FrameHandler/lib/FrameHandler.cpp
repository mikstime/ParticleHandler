//
// Created by Михаил on 2019-03-16.
//

#include <iostream>
#include <opencv2/imgproc.hpp>
#include "FrameHandler.h"
#include "GrayScaleFilter.h"
#include "EmphasizeFilter.h"
#include "TYPES.h"
using namespace mbtsky;
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
    filterApplier = new FilterApplier;
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
    filterApplier->applyFilters(currentFrame, currentFrame);
    // Filter second frame
    filterApplier->applyFilters(nextFrame, nextFrame);
}
void FrameHandler::__distinguish() {
    cv::Mat frame1gray, frame2gray;
    cv::cvtColor(currentFrame, frame1gray, cv::COLOR_BGR2GRAY);
    cv::cvtColor(nextFrame, frame2gray, cv::COLOR_BGR2GRAY);
    particleDistinguisher->process(frame1gray);
    currentCenters = particleDistinguisher->getCenters();
    particleDistinguisher->process(frame2gray);
    nextCenters = particleDistinguisher->getCenters();

}
void FrameHandler::__track() {
    positionTracker->setCenters(currentCenters, nextCenters);
    positionTracker->analyse();
    centerPositionChange = positionTracker->getUnitedCenters();
}
void FrameHandler::ProcessFrames() {
    __process();
}
FrameHandler::FrameHandler() {
    __setup();
}
void FrameHandler::__clearResults() {
    currentCenters.clear();
    nextCenters.clear();
    centerPositionChange.clear();
}
void FrameHandler::reset() {
    __clearResults();
    filterApplier->reset();
    particleDistinguisher->reset();
    positionTracker->reset();
}