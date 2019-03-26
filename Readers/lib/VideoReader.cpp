//
// Created by Михаил on 2019-03-17.
//

#include "VideoReader.h"
#include <iostream>
void VideoReader::readFile() {
    videoCapture.open(getPath(), cv::CAP_ANY);
}

cv::Mat VideoReader::getFrame(uint16_t id) {
    upperBorder = upperBorder <= videoCapture.get(cv::CAP_PROP_FRAME_COUNT) ?
            upperBorder : videoCapture.get(cv::CAP_PROP_FRAME_COUNT);

    if(id >= lowerBorder && id <= upperBorder) {
        videoCapture.set(cv::CAP_PROP_POS_FRAMES,id);
        videoCapture >> currentFrame;
        return currentFrame;
    } else {
        return cv::Mat();
    }
}
uint16_t VideoReader::getVideoSize() {
    return videoCapture.get(cv::CAP_PROP_FRAME_COUNT);
}
void VideoReader::reset() {
    videoCapture.release();
    resetPath();
}
void VideoReader::setBorders(uint16_t lowerBorder_, uint16_t upperBorder_) {
    if(lowerBorder_ < upperBorder_) {
        setBorders(upperBorder_, lowerBorder_);
    }
    lowerBorder = lowerBorder_;
    upperBorder = upperBorder_;
}
void VideoReader::setLowerBorder(uint16_t lowerBorder_) {
    if(lowerBorder_ > upperBorder) {
        setUpperBorder(lowerBorder_);
    }
    lowerBorder = lowerBorder_;
}
void VideoReader::setUpperBorder(uint16_t upperBorder_) {
    if(upperBorder_ < lowerBorder) {
        setLowerBorder(upperBorder_);
    }
    upperBorder = upperBorder_;
}
uint16_t VideoReader::getLowerBorder() {
    return lowerBorder;
}
uint16_t VideoReader::getUpperBorder() {
    return upperBorder;
}