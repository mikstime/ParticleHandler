//
// Created by Михаил on 2019-03-07.
//

#ifndef PARTICLEDISTINGUISHER_FILTER_H
#define PARTICLEDISTINGUISHER_FILTER_H

#include <opencv2/core/mat.hpp>
#include "TYPES.h"

class Filter {

public:
    virtual bool hasAtomic() = 0;
    virtual void setImage(const cv::Mat&) = 0;
    virtual void apply() = 0;
    virtual void applyAtomic(Pixel&, const int*) = 0;
    virtual cv::Mat getResult() = 0;
};


#endif //PARTICLEDISTINGUISHER_FILTER_H
