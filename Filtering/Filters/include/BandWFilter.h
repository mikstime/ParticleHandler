//
// Created by Михаил on 2019-03-10.
//

#ifndef PARTICLEDISTINGUISHER_BANDWFILTER_H
#define PARTICLEDISTINGUISHER_BANDWFILTER_H


#include "Filter.h"
#include <opencv2/core/core.hpp>
class BandWFilter: public Filter {
    cv::Mat image;
    bool __hasAtomic = true;
public:
    void setImage(const cv::Mat&);
    void apply();
    void applyAtomic(Pixel&, const int*);
    cv::Mat getResult();
    bool hasAtomic();
};


#endif //PARTICLEDISTINGUISHER_BANDWFILTER_H
