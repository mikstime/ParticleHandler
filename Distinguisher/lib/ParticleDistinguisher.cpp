//
// Created by Михаил on 2019-03-15.
//

#include <iostream>
#include "ParticleDistinguisher.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
typedef cv::Point3_<uint8_t > Pixel;
typedef std::vector<cv::Point> Points;

/*
 * File structure:
 *      setters
 *      private methods
 *      getters
 *      constructors
 */

// Setters
void ParticleDistinguisher::setImage(cv::Mat image_) {
    try {
        cvtColor(image_, image_, cv::COLOR_BGR2GRAY);
    }
    catch(...) {
        std::cerr << "ParticleDistinguisher: \n";
        std::cerr << "Input image should be in BGR mode\n" <<
                     "No image was set!\n";
        return;
    }
    if( image_.rows > 0) {
        image = image_;
        __clearResults();
        __process();
    } else {
        std::cerr << "ParticleDistinguisher: \n";
        std::cerr << "Input image must have non zero resolution\n" <<
                  "No image was set!\n";
    }
}
void ParticleDistinguisher::setRadius(uint8_t radius_) {
    radius = radius_;
}
// Private methods
void ParticleDistinguisher::__process() {
    __detectPoints();
    __filterResults();
    __computeCenters();
}
void ParticleDistinguisher::__detectPoints() {
    std::vector<Points> _contours;
    // Find contours of each(Most likely) particle
    findContours(image, _contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    contours = _contours;

}
void ParticleDistinguisher::__filterResults() {
    std::vector<Points> filtered;

    //Filter out contours with size less than ~ 1/6Particles area
    for(int i = 0; i < contours.size(); i++) {
        if (contours[i].size() > radius * radius)
            filtered.push_back(contours[i]);
    }

    contours = filtered;

}
void ParticleDistinguisher::__computeCenters() {
        Points result;

        for (int i=0; i < contours.size();i++) {
            //  Calculate moment for current counter.
            //  Since input is binary the second param is true
            cv::Moments m = cv::moments(contours[i],true);
            // Find center of masses and push it in result.
            result.push_back( cv::Point(m.m10/m.m00, m.m01/m.m00));
        }
        centers = result;

}
// Getters
cv::Mat ParticleDistinguisher::getImage() {
    return image;

}
uint8_t ParticleDistinguisher::getRadius() {
    return radius;
}
std::vector<Points> ParticleDistinguisher::getContours() {
    return contours;
}
Points ParticleDistinguisher::getCenters() {
    return centers;
}
//Constructors
ParticleDistinguisher::ParticleDistinguisher() {
    __setup();
}
ParticleDistinguisher::ParticleDistinguisher(uint8_t radius_) {
    __setup();
    radius = radius_;
}
void ParticleDistinguisher::__clearResults() {
    contours.clear();
    centers.clear();
}
void ParticleDistinguisher::__setup() {
    radius = 1;
}
void ParticleDistinguisher::reset() {
    __clearResults();
    __setup();
}