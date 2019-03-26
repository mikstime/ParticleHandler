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
    uint16_t lowerBorder, upperBorder;
protected:
    void setBorders(uint16_t, uint16_t);
    void setUpperBorder(uint16_t);
    void setLowerBorder(uint16_t);
public:
    uint16_t getLowerBorder();
    uint16_t getUpperBorder();
    void readFile();
    cv::Mat getFrame(uint16_t);
    uint16_t getVideoSize();
    void reset();
    friend class VideoReaderSettinger;
};


#endif //VIDEOREADER_VIDEOREADER_H
