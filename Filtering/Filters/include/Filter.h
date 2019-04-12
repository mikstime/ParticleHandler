//
// Created by Михаил on 2019-03-07.
//

#ifndef PARTICLEDISTINGUISHER_FILTER_H
#define PARTICLEDISTINGUISHER_FILTER_H

#include <opencv2/core/core.hpp>
#include "TYPES.h"
#include <LoadableObjectBase.h>
namespace mbtsky::filters {
    using namespace mbtsky::filters;
    class Filter : public LoadableObjectBase {

    public:
        //*********************************************************************
        // Return true if has
        //*********************************************************************
        virtual bool hasAtomic() = 0;

        //*********************************************************************
        // apply
        // @param image - source image
        // @param result - resulting image
        // it can be the same image object!
        // Apply filter for chosen image
        //*********************************************************************
        virtual void apply(const cv::Mat& image, cv::Mat& result) = 0;

        //*********************************************************************
        // applyAtomic
        // Apply atomic filter for chosen image
        //*********************************************************************
        virtual void applyAtomic(Pixel &, const int *) = 0;
    };
}

#endif //PARTICLEDISTINGUISHER_FILTER_H
