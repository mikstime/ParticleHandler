//
// Created by Михаил on 2019-03-18.
//

#include "PositionAnalyser.h"
using namespace mbtsky;
void PositionAnalyser::__clearResults() {
    videoReader->reset();
    frameHandler->reset();
    positionHandler->reset();
    currentPositions.clear();
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
    frameHandler->ProcessFrames(frame1, frame2, currentPositions);
}
void PositionAnalyser::ProcessVideo() {
    //@TODO do it in parallel
    //@TODO results could be stored in map by thread ID
    //@TODO and combined after processing
    uint16_t start = videoReader->getLowerBorder();
    uint16_t end = videoReader->getUpperBorder();
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
    videoReader->reset();
    frameHandler->reset();
    positionHandler->reset();
    positionLogger->resetPath();
}
PositionAnalyser::PositionAnalyser(mbtsky::PositionAnalyser &pa) {
    // copy constructor
    videoReader = new VideoReader(*pa.videoReader);
    frameHandler = new FrameHandler(*pa.frameHandler);
    positionHandler = new PositionHandler(*pa.positionHandler);
    positionLogger = new PositionLogger(*pa.positionLogger);
    currentPositions.assign(pa.currentPositions.begin(),
            pa.currentPositions.end());
}