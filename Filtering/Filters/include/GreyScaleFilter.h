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
        // image used for processing
        //*********************************************************************
        cv::Mat image;

        //*********************************************************************
        // always true for GreyScaleFilter
        //*********************************************************************
        static const bool __hasAtomic = true;

        //*********************************************************************
        // intensity of greyscale filter
        //*********************************************************************
        double intensity;

        bool isValidProto(const nlohmann::json &);

    public:
        GreyScaleFilter() {
            intensity = 1;
        }

        GreyScaleFilter(GreyScaleFilter &grayScaleFilter) {
            intensity = grayScaleFilter.intensity;
            image = grayScaleFilter.image;
        }

        void setImage(const cv::Mat &) override;

        void apply() override;

        void applyAtomic(Pixel &, const int *) override;

        cv::Mat& getResult() override;

        bool hasAtomic() override;

        void setParams(const nlohmann::json &) override;
    };
}


#endif //PARTICLEDISTINGUISHER_GRAYSCALEFILTER_H
