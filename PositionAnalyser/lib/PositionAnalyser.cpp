//
// Created by Михаил on 2019-03-18.
//

#include <iostream>
#include <opencv2/highgui.hpp>
#include "PositionAnalyser.h"

void PositionAnalyser::__clearResults() {
    currentPositions.clear();
    //@TODO make all modules 'resettable'

    videoReader->reset();
    frameHandler->reset();
    positionLogger->reset();
    positionHandler->reset();
}
void PositionAnalyser::__setup() {
    __setupVideoReader();
    __setupFrameHandler();
    __setupPositionHandler();
    __setupPositionLogger();
}
void PositionAnalyser::__setupVideoReader() {
    videoReader = new VideoReader;
}
void PositionAnalyser::__setupFrameHandler() {
    frameHandler = new FrameHandler;
    frameHandler->setParticleRadius(particleRadius);
}
void PositionAnalyser::__setupPositionLogger() {
    positionLogger = new PositionLogger;
}
void PositionAnalyser::__setupPositionHandler() {
    positionHandler = new PositionHandler;
    positionHandler->setParticleRadius(particleRadius);
}
void PositionAnalyser::loadVideo(std::string path) {
    videoReader->setPath(path);
    videoReader->readFile();
}
void PositionAnalyser::__process2Frames(uint16_t frame1Id, uint16_t frame2Id) {
    cv::Mat frame1 = videoReader->getFrame(frame1Id);
    cv::Mat frame2 = videoReader->getFrame(frame2Id);
    frameHandler->setFrames(frame1, frame2);
    frameHandler->ProcessFrames();
    currentPositions = frameHandler->getPositionChange();
}
void PositionAnalyser::ProcessVideo() {
    //@TODO do it in parallel
    //@TODO results could be stored in map by thread ID
    //@TODO and combined after processing
    for(uint16_t i = start; i < end; i += 2) {
        __process2Frames(i, i + 1);
        positionHandler->setPositionsToProcess(currentPositions);
        positionHandler->combine();
        std::cout << "frames " << i << " and " << i + 1 << " processed\n";
    }
}
PositionAnalyser::PositionAnalyser() {
    __setup();
}
void PositionAnalyser::savePositionList(std::string path) {
    positionLogger->setPath(path);
    positionLogger->saveCoordinates(positionHandler->getProcessedPositions());
}
void PositionAnalyser::setParticleRadius(uint8_t particleRadius_) {
    particleRadius = particleRadius_;
    frameHandler->setParticleRadius(particleRadius_);
    positionHandler->setParticleRadius(particleRadius_);
}
void PositionAnalyser::reset() {
    __clearResults();
}
void PositionAnalyser::setBorders(uint16_t start_, uint16_t end_) {
    if(start_ > end_)
        setBorders(end_, start_);
    uint16_t size = videoReader->getVideoSize();
    start = start_ < size ? start_ : size - 1;
    end = end_ < size ? end_ : size - 1;

}