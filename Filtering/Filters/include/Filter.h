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
        // setImage
        // @param image - image to be modified
        // Set image for processing
        //*********************************************************************
        virtual void setImage(const cv::Mat &image) = 0;

        //*********************************************************************
        // apply
        // Apply filter for chosen image
        //*********************************************************************
        virtual void apply() = 0;

        //*********************************************************************
        // applyAtomic
        // Apply atomic filter for chosen image
        //*********************************************************************
        virtual void applyAtomic(Pixel &, const int *) = 0;

        //*********************************************************************
        // getResult
        // Return result of processing
        //*********************************************************************
        virtual cv::Mat &getResult() = 0;
    };
}

#endif //PARTICLEDISTINGUISHER_FILTER_H
