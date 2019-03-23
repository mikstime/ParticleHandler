//
// Created by Михаил on 2019-03-06.
//

#include "ImageHandler.h"
#include "opencv2/core.hpp"
#include <vector>
#include <random>
typedef cv::Point3_<uint8_t> Pixel;
using std::string;
// Image input and output
cv::Mat ImageHandler::getImage() {
    return image;
}

/*
 * Routing filters to FilterApplier
 */
void ImageHandler::setFilter(Filter *filter_) {
    filterApplier->setFilter(filter_);
}
void ImageHandler::addFilter(Filter *filter_) {
    filterApplier->addFilter(filter_);
}
void ImageHandler::addFilters(std::vector<Filter *> &filters_) {
    filterApplier->addFilters(filters_);
}
int ImageHandler::deleteFilter(Filter *filter_) {
    return filterApplier->deleteFilter(filter_);
}
void ImageHandler::applyFilters() {
    image = filterApplier->applyFilters(image);
}
void ImageHandler::deleteFilters() {
    filterApplier->deleteFilters();
}
void ImageHandler::setImage(cv::Mat image_) {
    image = image_;
}
void ImageHandler::reset() {
    image.release();
    filterApplier->reset();
}