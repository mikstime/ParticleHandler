//
// Created by Михаил on 2019-03-17.
//

#ifndef VIDEOREADER_VIDEOREADER_H
#define VIDEOREADER_VIDEOREADER_H

#include <opencv2/videoio.hpp>
#include "FileReader.h"

class VideoReader: public FileReader {
    cv::VideoCapture videoCapture;
    cv::Mat currentFrame;
public:
    void readFile();
    cv::Mat getFrame(uint16_t);
    uint16_t getVideoSize();
    void reset();
};


#endif //VIDEOREADER_VIDEOREADER_H
