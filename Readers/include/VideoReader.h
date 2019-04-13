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
namespace mbtsky {
    class VideoReader : public FileReader, public LoadableObjectBase {
        //*********************************************************************
        // variable for storing video stream
        //*********************************************************************
        cv::VideoCapture videoCapture;

        //*********************************************************************
        // variable for storing current result
        //*********************************************************************
        cv::Mat currentFrame;

        //*********************************************************************
        // start end end of the stream
        //*********************************************************************
        uint16_t lowerBorder, upperBorder;

        //*********************************************************************
        // isValidProto
        // validate object's prototype
        //*********************************************************************
        bool isValidProto(const json &);

    public:

        //*********************************************************************
        // setBorders
        // set lower and upper borders
        //*********************************************************************
        void setBorders(uint16_t, uint16_t);

        //*********************************************************************
        // setUpperBorder
        //*********************************************************************
        void setUpperBorder(uint16_t);

        //*********************************************************************
        // setLowerBorder
        //*********************************************************************
        void setLowerBorder(uint16_t);

        //*********************************************************************
        // getLowerBorder
        // @result  lowerBorder
        //*********************************************************************
        uint16_t getLowerBorder();

        //*********************************************************************
        // getUpperBorder
        // @result upperBorder
        //*********************************************************************
        uint16_t getUpperBorder();

        //*********************************************************************
        // readFile
        // read file  using path module
        //*********************************************************************
        void readFile() override;

        //*********************************************************************
        // getFrame
        // @result n-th frame from stream by
        //*********************************************************************
        cv::Mat getFrame(uint16_t);

        //*********************************************************************
        // getVideoSize
        //  @result size of the stream
        //*********************************************************************
        uint16_t getVideoSize();

        //*********************************************************************
        // remove stored data and release stream
        //*********************************************************************
        void reset();

        //*********************************************************************
        // setParams
        // parse object's params via json
        //*********************************************************************
        void setParams(const json &) override;
    };
}

#endif //VIDEOREADER_VIDEOREADER_H
