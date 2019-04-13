//
// Created by Михаил on 2019-03-14.
//

#include "EmphasizeFilter.h"

using nlohmann::json;
using namespace mbtsky::filters;

void EmphasizeFilter::applyAtomic(Pixel &, const int *) {
    //Do nothing
}
void EmphasizeFilter::apply(const cv::Mat& source, cv::Mat& result) {
    // Reduce background noise
    cv::GaussianBlur(source, result, cv::Size(gaussian, gaussian), 0, 0);
    // Remove false particles
    cv::medianBlur(result, result, lambda);
    // Get rid of the background

    cv::threshold(result, result, 120, 255, cv::THRESH_BINARY);

    cv::dilate(result, result, getStructuringElement(cv::MORPH_RECT, cv::Size (dilation, dilation)));

}

void EmphasizeFilter::setParams(const nlohmann::json & FilterDesc) {

    if(!isValidProto(FilterDesc))
        return;
    // radius should be odd number
    gaussian = FilterDesc["gaussian"].get<uint8_t>() % 2 == 1 ?
        FilterDesc["gaussian"].get<uint8_t>()  :
        FilterDesc["gaussian"].get<uint8_t>()  + 1 ;
    dilation = FilterDesc["dilation"].get<uint8_t >();
    // lambda is just a positive integer
    lambda = FilterDesc["lambda"].get<uint8_t>();

}
bool EmphasizeFilter::isValidProto(const nlohmann::json &objDesc) {

    return objDesc["gaussian"].type() == json::value_t::number_unsigned &&
           objDesc["lambda"].type() == json::value_t::number_unsigned &&
           objDesc["dilation"].type() == json::value_t::number_unsigned;
}