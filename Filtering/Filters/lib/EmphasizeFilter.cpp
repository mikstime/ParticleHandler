//
// Created by Михаил on 2019-03-14.
//

#include "EmphasizeFilter.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <iostream>
#include "TYPES.h"
#include <limits>
using nlohmann::json;
bool EmphasizeFilter::hasAtomic() {
    return __hasAtomic;
}
cv::Mat EmphasizeFilter::getResult() {
    return image;
}

void EmphasizeFilter::setImage(const cv::Mat& image_) {
    image = image_;
}
void EmphasizeFilter::applyAtomic(Pixel &, const int *) {
    //Do nothing
}
void EmphasizeFilter::apply() {
    // Reduce background noise
    cv::GaussianBlur(image, image, cv::Size(2 * radius + 1, 2 * radius + 1), 0, 0);
    // Remove false particles
    cv::medianBlur(image, image, lambda);
    // Get rid of the background

    cv::threshold(image, image, 120, 255, cv::THRESH_BINARY);

    cv::dilate(image, image, getStructuringElement(cv::MORPH_RECT, cv::Size (radius, radius)));

}
EmphasizeFilter::EmphasizeFilter() {
    radius = lambda = 1;
}
void EmphasizeFilter::setParams(const nlohmann::json & FilterDesc) {

    if(!isValidProto(FilterDesc))
        return;
    // radius should be odd number
    radius = FilterDesc["radius"].get<uint8_t>() % 2 == 1 ?
        FilterDesc["radius"].get<uint8_t>()  :
        FilterDesc["radius"].get<uint8_t>()  + 1 ;
    // lambda is just a positive integer
    lambda = FilterDesc["lambda"].get<uint8_t>();

}
bool EmphasizeFilter::isValidProto(const nlohmann::json &objDesc) {

    return objDesc["radius"].type() == json::value_t::number_unsigned &&
           objDesc["lambda"].type() == json::value_t::number_unsigned &&
           objDesc["radius"].get<uint8_t >() > 0 && objDesc["radius"].get<uint8_t >() < 100 &&
           objDesc["lambda"].get<uint8_t >() > 0 && objDesc["lambda"].get<uint8_t >() < 100;
}