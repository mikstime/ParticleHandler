//
// Created by Михаил on 2019-03-15.
//

#include <iostream>
#include "ParticleRecognizer.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "TYPES.h"
using namespace mbtsky;
// Private methods
void ParticleRecognizer::__process() {
    __detectPoints();
    __filterResults();
    __computeCenters();
}
void ParticleRecognizer::__detectPoints() {
    std::vector<Points> _contours;
    // Find contours of each(Most likely) particle
    findContours(image, _contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    contours = _contours;

}
void ParticleRecognizer::__filterResults() {
    std::vector<Points> filtered;

    //Filter out contours with size less than ~ 1/6Particles area
    for(int i = 0; i < contours.size(); i++) {
        if (contours[i].size() > particleRadius * particleRadius / 6)
            filtered.push_back(contours[i]);
    }

    contours = filtered;

}
void ParticleRecognizer::__computeCenters() {
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

void ParticleRecognizer::process(const cv::Mat& image_) {
    image = image_;
    __clearResults();
    __process();
    image.release();
}
void ParticleRecognizer::setParams(const json& objDesc) {
    if(!isValidProto(objDesc)) {
        return;
    }
    particleRadius = objDesc["particleRadius"].get<uint8_t >();
}
bool ParticleRecognizer::isValidProto(const json &objDesc) {
    //@particleRadius is positive number.
    return objDesc["particleRadius"].type() == json::value_t::number_unsigned &&
           objDesc["particleRadius"].get<uint8_t >() > 0;
}