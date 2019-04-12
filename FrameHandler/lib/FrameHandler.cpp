//
// Created by Михаил on 2019-03-16.
//

#include <iostream>
#include <opencv2/imgproc.hpp>
#include "FrameHandler.h"
#include "GreyScaleFilter.h"
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
    particleRecognizer = new ParticleRecognizer;
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
    particleRecognizer->process(frame1gray);
    currentCenters = particleRecognizer->getCenters();
    particleRecognizer->process(frame2gray);
    nextCenters = particleRecognizer->getCenters();

}
void FrameHandler::__track() {
    positionTracker->analyse(currentCenters, nextCenters, centerPositionChange);
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
    particleRecognizer->reset();
    positionTracker->reset();
}