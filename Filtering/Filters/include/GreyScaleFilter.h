//
// Created by Михаил on 2019-03-10.
//

#ifndef PARTICLEDISTINGUISHER_GRAYSCALEFILTER_H
#define PARTICLEDISTINGUISHER_GRAYSCALEFILTER_H


#include <LoadableObjectBase.h>
#include "Filter.h"
namespace mbtsky::filters {
    using namespace mbtsky::filters;

    class GreyScaleFilter : public Filter {

        //*********************************************************************
        // always true for GreyScaleFilter
        //*********************************************************************
        static const bool __hasAtomic = true;

        //*********************************************************************
        // intensity of greyscale filter
        //*********************************************************************
        double intensity;
        //*********************************************************************
        // isValidProto
        // @param json object Descriptor
        // Validate if descriptor is correct
        //*********************************************************************
        bool isValidProto(const nlohmann::json & objDesc);

    public:
        //*********************************************************************
        // Default constructor
        //*********************************************************************
        GreyScaleFilter() {
            intensity = 1;
        }

        //*********************************************************************
        // Copy constructor
        //*********************************************************************
        GreyScaleFilter(GreyScaleFilter &grayScaleFilter) {
            intensity = grayScaleFilter.intensity;
        }

        //*********************************************************************
        // apply
        // Apply filter to image
        // @params are described in Filter.h
        //*********************************************************************
        void apply(const cv::Mat& source, cv::Mat& result) override;

        //*********************************************************************
        // applyAtomic
        // Apply filter to concrete pixel
        //*********************************************************************
        void applyAtomic(Pixel &, const int *) override;

        //*********************************************************************
        // hasAtomic
        // Always true for GrayScaleFilter
        //*********************************************************************
        bool hasAtomic() override;

        //*********************************************************************
        // setParams
        // Set params from object descriptor
        //*********************************************************************
        void setParams(const nlohmann::json &) override;
    };
}


#endif //PARTICLEDISTINGUISHER_GRAYSCALEFILTER_H
