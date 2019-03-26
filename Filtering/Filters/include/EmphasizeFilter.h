//
// Created by Михаил on 2019-03-14.
//

#ifndef PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H
#define PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H

#include <opencv2/core/core.hpp>
#include "Filter.h"
#include <vector>
#include "TYPES.h"

class EmphasizeFilter: public Filter {
    cv::Mat image;
    bool __hasAtomic = false;
    uint8_t radius;
    uint8_t lambda;
protected:
    void setRadius(uint8_t);
    void setLambda(uint8_t);
public:
    bool hasAtomic();
    void applyAtomic(Pixel&, const int*);
    void apply();
    cv::Mat getResult();
    void setImage(const cv::Mat&);
    EmphasizeFilter();

    friend class EmphasizeFilterSettinger;
};


#endif //PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H
