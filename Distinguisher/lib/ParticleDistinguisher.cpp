//
// Created by Михаил on 2019-03-15.
//

#include <iostream>
#include "ParticleDistinguisher.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "TYPES.h"

/*
 * File structure:
 *      setters
 *      private methods
 *      getters
 *      constructors
 */

// Setters
void ParticleDistinguisher::setImage(const cv::Mat& image_) {
    image = image_;
    __clearResults();
    __process();
}
void ParticleDistinguisher::setParticleRadius(uint8_t particleRadius_) {
    particleRadius = particleRadius_;
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
        if (contours[i].size() > particleRadius * particleRadius / 6)
            filtered.push_back(contours[i]);
    }

    contours = filtered;

}
void ParticleDistinguisher::__computeCenters() {
        Coordinates result;

        for (int i=0; i < contours.size();i++) {
            //  Calculate moment for current counter.
            //  Since input is binary the second param is true
            cv::Moments m = cv::moments(contours[i],true);
            // Find center of masses and push it in result.
            result.push_back( Coordinate(m.m10/m.m00, m.m01/m.m00));
        }
        centers = result;
}
// Getters
cv::Mat ParticleDistinguisher::getImage() {
    return image;

}
uint8_t ParticleDistinguisher::getRadius() {
    return particleRadius;
}
std::vector<Points> ParticleDistinguisher::getContours() {
    return contours;
}
Coordinates ParticleDistinguisher::getCenters() {
    return centers;
}
//Constructors
ParticleDistinguisher::ParticleDistinguisher() {

}
void ParticleDistinguisher::__clearResults() {
    contours.clear();
    centers.clear();
}
void ParticleDistinguisher::reset() {
    __clearResults();
}
void ParticleDistinguisher::process() {
    __clearResults();
    __process();
}