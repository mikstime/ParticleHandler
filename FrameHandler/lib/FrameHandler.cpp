//
// Created by Михаил on 2019-03-16.
//

#include "FrameHandler.h"

using namespace mbtsky;

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
void FrameHandler::ProcessFrames(
        const cv::Mat &firstFrame,
        const cv::Mat &secondFrame,
        std::vector<Coordinates> &result
) {
    firstFrame.copyTo(currentFrame);
    secondFrame.copyTo(nextFrame);
    __process();
    result.clear();
    result.assign(centerPositionChange.begin(), centerPositionChange.end());
    __clearResults();
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
FrameHandler::FrameHandler(FrameHandler& fh) {
    // Copy constructor
    filterApplier = new FilterApplier(*fh.filterApplier);
    particleRecognizer = new ParticleRecognizer(*fh.particleRecognizer);
    positionTracker = new PositionTracker(*fh.positionTracker);
    currentCenters.assign(fh.currentCenters.begin(),
                          fh.currentCenters.end());
    nextCenters.assign(fh.nextCenters.begin(),
                       fh.nextCenters.end());
    currentFrame = fh.currentFrame;
    nextFrame = fh.nextFrame;
    centerPositionChange.assign(fh.centerPositionChange.begin(),
                                fh.centerPositionChange.end());
}