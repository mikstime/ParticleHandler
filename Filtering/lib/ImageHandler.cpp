//
// Created by Михаил on 2019-03-06.
//

#include "ImageHandler.h"
#include "FilterApplierSettinger.h"
#include "SettingsHandler.h"
#include "opencv2/core.hpp"
#include <vector>
#include <random>
#include "TYPES.h"
using std::string;
// Image input and output
cv::Mat ImageHandler::getImage() {
    return image;
}
void ImageHandler::applyFilters() {
    filterApplier->applyFilters(image, image);
}
void ImageHandler::setImage(cv::Mat& image_) {
    image = image_;
}
void ImageHandler::reset() {
    image.release();
    filterApplier->reset();
}
FilterApplier* ImageHandler::getFilterApplier() {
    return filterApplier;
}