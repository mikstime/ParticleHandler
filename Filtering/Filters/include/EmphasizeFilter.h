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
    bool isValidProto(const nlohmann::json&);
public:
    virtual bool hasAtomic();
    virtual void applyAtomic(Pixel&, const int*);
    virtual void apply();
    virtual cv::Mat getResult();
    virtual void setImage(const cv::Mat&);
    EmphasizeFilter();

    virtual void setParams(const nlohmann::json&);

};


#endif //PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H
