//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_IMAGEREADER_H
#define PARTICLEDISTINGUISHER_IMAGEREADER_H


#include <opencv2/core/mat.hpp>
#include <string>
using std::string;
class ImageReader {
public:
    void readImage(string, string, string, cv::Mat &);
    void saveImage(string, cv::Mat &);
};

#endif //PARTICLEDISTINGUISHER_IMAGEREADER_H
