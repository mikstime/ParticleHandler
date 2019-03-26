//
// Created by Михаил on 2019-03-06.
//

#ifndef PARTICLEDISTINGUISHER_IMAGEHANDLER_H
#define PARTICLEDISTINGUISHER_IMAGEHANDLER_H

#include "opencv2/core/core.hpp"
#include "FilterApplier.h"
#include "TYPES.h"

class ImageHandler {
    cv::Mat image;
    FilterApplier* filterApplier = new FilterApplier;
public:
    // Operations with Image
    void setImage(cv::Mat&);
    cv::Mat getImage();

    FilterApplier* getFilterApplier();
    void applyFilters();

    void reset();
};


#endif //PARTICLEDISTINGUISHER_IMAGEHANDLER_H
