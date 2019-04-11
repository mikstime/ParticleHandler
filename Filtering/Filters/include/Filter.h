//
// Created by Михаил on 2019-03-07.
//

#ifndef PARTICLEDISTINGUISHER_FILTER_H
#define PARTICLEDISTINGUISHER_FILTER_H

#include <opencv2/core/core.hpp>
#include "TYPES.h"
#include <LoadableObjectBase.h>
class Filter : public LoadableObjectBase {

public:
    virtual bool hasAtomic() = 0;
    virtual void setImage(const cv::Mat&) = 0;
    virtual void apply() = 0;
    virtual void applyAtomic(Pixel&, const int*) = 0;
    virtual cv::Mat getResult() = 0;
    virtual void setParams(const nlohmann::json&) = 0;
};


#endif //PARTICLEDISTINGUISHER_FILTER_H
