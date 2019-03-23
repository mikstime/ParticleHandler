//
// Created by Михаил on 2019-03-14.
//

#ifndef PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H
#define PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H

#include <opencv2/core/core.hpp>
#include "Filter.h"
#include <vector>

typedef cv::Point3_<uint8_t> Pixel;

class EmphasizeFilter: public Filter {
    cv::Mat image;
    bool __hasAtomic = false;
    uint8_t radius = 3;
    uint8_t lambda = 7;
public:
    bool hasAtomic();
    void applyAtomic(Pixel&, const int*);
    void apply();

    void setImage(cv::Mat*);
    cv::Mat* getResult();
    EmphasizeFilter();
    //@TODO implement parameter changing
    EmphasizeFilter(std::vector<uint8_t >);

    void updateParams(std::vector<uint8_t >);
};


#endif //PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H
