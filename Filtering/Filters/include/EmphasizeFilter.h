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

namespace mbtsky::filters {

    class EmphasizeFilter : public Filter {

        //*********************************************************************
        // always false for EmphasizeFilter
        //*********************************************************************
        const static bool __hasAtomic = false;

        //*********************************************************************
        // Used for GaussianFilter, always odd
        //*********************************************************************
        uint8_t gaussian;

        //*********************************************************************
        // Dilation radius
        //*********************************************************************
        uint8_t dilation;

        //*********************************************************************
        // MedianBlur param
        //*********************************************************************
        uint8_t lambda;

        //*********************************************************************
        // isValidProto
        // Validate json object descriptor
        //*********************************************************************
        bool isValidProto(const nlohmann::json &);

    public:

        //*********************************************************************
        // Default constructor
        //*********************************************************************
        EmphasizeFilter() {
            gaussian = dilation = lambda = 1;
        }

        //*********************************************************************
        // Copy constructor
        //*********************************************************************
        EmphasizeFilter(EmphasizeFilter &filter) {
            gaussian = filter.gaussian;
            dilation = filter.dilation;
            lambda = filter.lambda;
        }

        //*********************************************************************
        // hasAtomic
        // always false for EmphasizeFilter
        //*********************************************************************
        bool hasAtomic() override { return __hasAtomic; };

        //*********************************************************************
        // applyAtomic
        // described in Filter.h
        //*********************************************************************
        void applyAtomic(Pixel &, const int *) override;

        //*********************************************************************
        // apply
        // described in Filter.h
        //*********************************************************************
        void apply(const cv::Mat &source, cv::Mat &result) override;

        //*********************************************************************
        // setParams
        // Set params from object descriptor
        //*********************************************************************
        void setParams(const nlohmann::json &) override;

    };
}
#endif //PARTICLEDISTINGUISHER_EMPHASIZEFILTER_H
