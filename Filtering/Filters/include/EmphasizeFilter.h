//
// Created by Михаил on 2019-03-14.
//

#ifndef PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H
#define PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H

#include "Filter.h"
#include <opencv2/imgproc.hpp>
#include <vector>
#include <limits>
#include "TYPES.h"
using namespace mbtsky::filters;
class EmphasizeFilter: public Filter {
    cv::Mat image;
    const static bool __hasAtomic = false;
    uint8_t radius;
    uint8_t lambda;
    bool isValidProto(const nlohmann::json&);
public:
    EmphasizeFilter() {
        radius = lambda = 1;
    }
    EmphasizeFilter(EmphasizeFilter& filter) {
        radius = filter.radius;
        lambda = filter.lambda;
        image  = filter.image;
    }
    bool hasAtomic() override { return __hasAtomic; };
    void applyAtomic(Pixel&, const int*) override;
    void apply() override;
    cv::Mat& getResult() override;
    void setImage(const cv::Mat&) override;

    void setParams(const nlohmann::json&) override;

};


#endif //PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H
