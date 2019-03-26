//
// Created by Михаил on 2019-03-10.
//


#include <opencv2/core.hpp>
#include "BandWFilter.h"
#include "TYPES.h"

void BandWFilter::setImage(const cv::Mat& image_) {
    image = image_;
}
cv::Mat BandWFilter::getResult() {
    return image;
}
void BandWFilter::apply() {
    image.forEach<Pixel>(
            [&](Pixel& pixel, const int* position) {
                applyAtomic(pixel, position);
            }
     );
}
void BandWFilter::applyAtomic(Pixel & pixel, const int *position) {
    int av = (pixel.x + pixel.y + pixel.z) / 3;
    pixel.x = pixel.y = pixel.z = av;
}
bool BandWFilter::hasAtomic() {
    return __hasAtomic;
}