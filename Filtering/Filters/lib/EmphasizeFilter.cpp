//
// Created by Михаил on 2019-03-14.
//

#include "EmphasizeFilter.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include "TYPES.h"

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
void EmphasizeFilter::setRadius(uint8_t radius_) {
    radius = radius_;
}
void EmphasizeFilter::setLambda(uint8_t lambda_) {
    lambda = lambda_;
}