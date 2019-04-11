//
// Created by Михаил on 2019-03-10.
//


#include <opencv2/core.hpp>
#include <iostream>
#include "GrayScaleFilter.h"
#include "TYPES.h"
using nlohmann::json;
void GrayScaleFilter::setImage(const cv::Mat& image_) {
    image = image_;
}
cv::Mat GrayScaleFilter::getResult() {
    return image;
}
void GrayScaleFilter::apply() {
    image.forEach<Pixel>(
            [&](Pixel& pixel, const int* position) {
                applyAtomic(pixel, position);
            }
     );
}
void GrayScaleFilter::applyAtomic(Pixel & pixel, const int *position) {
    int av = (pixel.x + pixel.y + pixel.z) / 3;
    pixel.x = (uint8_t)( (1 - intensity) * (pixel.x - av) + av);
    pixel.y = (uint8_t)( (1 - intensity) * (pixel.y - av) + av);
    pixel.z = (uint8_t)( (1 - intensity) * (pixel.z - av) + av);
}
bool GrayScaleFilter::hasAtomic() {
    return __hasAtomic;
}
 void GrayScaleFilter::setParams(const nlohmann::json &objDesc) {
    if(!isValidProto(objDesc))
        return;
    intensity = objDesc["intensity"].get<double>();
}
bool GrayScaleFilter::isValidProto(const nlohmann::json &objDesc) {

    return (objDesc["intensity"].type() == json::value_t::number_float ||
            objDesc["intensity"].type() == json::value_t::number_unsigned) &&
            objDesc["intensity"].get<double>() >= 0 &&
            objDesc["intensity"].get<double>() <= 1;

}