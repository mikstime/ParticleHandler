//
// Created by Михаил on 2019-03-16.
//

#include "ImageReader.h"
#include <string>
#include <opencv2/highgui/highgui.hpp>

using std::string;
void ImageReader::readImage(string dir, string name, string ext, cv::Mat &image) {
    string path = dir + name + ext;
    image = cv::imread(path, cv::IMREAD_ANYCOLOR);
}
void ImageReader::saveImage(string path, cv::Mat & image) {
    cv::imwrite(path, image);
}