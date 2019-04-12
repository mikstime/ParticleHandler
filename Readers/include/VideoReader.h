//
// Created by Михаил on 2019-03-17.
//

#ifndef VIDEOREADER_VIDEOREADER_H
#define VIDEOREADER_VIDEOREADER_H

#include <opencv2/videoio.hpp>
#include <LoadableObjectBase.h>
#include "FileReader.h"
#include <json.hpp>
using nlohmann::json;
class VideoReader: public FileReader, public LoadableObjectBase {
    cv::VideoCapture videoCapture;
    cv::Mat currentFrame;
    uint16_t lowerBorder, upperBorder;
    bool isValidProto(const json&);
public:

    void setBorders(uint16_t, uint16_t);
    void setUpperBorder(uint16_t);
    void setLowerBorder(uint16_t);

    uint16_t getLowerBorder();
    uint16_t getUpperBorder();
    void readFile();
    cv::Mat getFrame(uint16_t);
    uint16_t getVideoSize();
    void reset();
    void setParams(const json&);
};


#endif //VIDEOREADER_VIDEOREADER_H
