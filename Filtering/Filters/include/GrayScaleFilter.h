//
// Created by Михаил on 2019-03-10.
//

#ifndef PARTICLEDISTINGUISHER_GRAYSCALEFILTER_H
#define PARTICLEDISTINGUISHER_GRAYSCALEFILTER_H


#include "Filter.h"
#include <opencv2/core/core.hpp>
#include <LoadableObjectBase.h>
class GrayScaleFilter: public Filter {
    cv::Mat image;
    bool __hasAtomic = true;
    double intensity = 1;
    bool isValidProto(const nlohmann::json&);
public:
    virtual void setImage(const cv::Mat&);
    virtual void apply();
    virtual void applyAtomic(Pixel&, const int*);
    virtual cv::Mat getResult();
    virtual bool hasAtomic();

    virtual void setParams(const nlohmann::json&);
};


#endif //PARTICLEDISTINGUISHER_GRAYSCALEFILTER_H
