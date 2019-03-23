//
// Created by Михаил on 2019-03-17.
//

#include "VideoReader.h"
void VideoReader::readFile() {
    videoCapture.open(getPath(), cv::CAP_ANY);
}

cv::Mat VideoReader::getFrame(uint16_t id) {
    if(id > 0 && id < videoCapture.get(cv::CAP_PROP_FRAME_COUNT)) {
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