//
// Created by Михаил on 2019-03-18.
//

#include <iostream>
#include <opencv2/highgui.hpp>
#include "PositionAnalyser.h"
#include "TYPES.h"
void PositionAnalyser::__clearResults() {
    currentPositions.clear();

    videoReader->reset();
    frameHandler->reset();
    positionLogger->reset();
    positionHandler->reset();
}
void PositionAnalyser::__setup() {
    videoReader = new VideoReader;
    frameHandler = new FrameHandler;
    positionLogger = new PositionLogger;
    positionHandler = new PositionHandler;
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
    start = videoReader->getLowerBorder();
    end = videoReader->getUpperBorder();
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
void PositionAnalyser::reset() {
    __clearResults();
}
FrameHandler* PositionAnalyser::getFrameHandler() {
    return frameHandler;
}
PositionHandler* PositionAnalyser::getPositionHandler() {
    return positionHandler;
}
PositionLogger* PositionAnalyser::getPositionLogger() {
    return positionLogger;
}
VideoReader* PositionAnalyser::getVideoReader() {
    return videoReader;
}