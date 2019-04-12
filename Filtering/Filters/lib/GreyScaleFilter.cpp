//
// Created by Михаил on 2019-03-10.
//


#include "GreyScaleFilter.h"
using nlohmann::json;
using namespace mbtsky::filters;

void GreyScaleFilter::apply(const cv::Mat& source, cv::Mat& result) {
    result = source;
    result.forEach<Pixel>(
            [&](Pixel& pixel, const int* position) {
                applyAtomic(pixel, position);
            }
     );
}
void GreyScaleFilter::applyAtomic(Pixel & pixel, const int *position) {
    int av = (pixel.x + pixel.y + pixel.z) / 3;
    pixel.x = (uint8_t)( (1 - intensity) * (pixel.x - av) + av);
    pixel.y = (uint8_t)( (1 - intensity) * (pixel.y - av) + av);
    pixel.z = (uint8_t)( (1 - intensity) * (pixel.z - av) + av);
}
bool GreyScaleFilter::hasAtomic() {
    return __hasAtomic;
}
 void GreyScaleFilter::setParams(const nlohmann::json &objDesc) {
    if(!isValidProto(objDesc))
        return;
    intensity = objDesc["intensity"].get<double>();
}
bool GreyScaleFilter::isValidProto(const nlohmann::json &objDesc) {

    return (objDesc["intensity"].type() == json::value_t::number_float ||
            objDesc["intensity"].type() == json::value_t::number_unsigned) &&
            objDesc["intensity"].get<double>() >= 0 &&
            objDesc["intensity"].get<double>() <= 1;

}