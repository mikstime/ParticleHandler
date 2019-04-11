//
// Created by Михаил on 2019-03-15.
//

#ifndef PARTICLEDISTINGUISHER_PARTICLEDISTINGUISHER_H
#define PARTICLEDISTINGUISHER_PARTICLEDISTINGUISHER_H


#include "opencv2/core/core.hpp"
#include "TYPES.h"
#include <LoadableObjectBase.h>
using nlohmann::json;
class ParticleDistinguisher : public LoadableObjectBase {
    cv::Mat image;
    // Radius of a particle
    uint8_t particleRadius;
    // variable for storing particles
    std::vector<Points> contours;
    // variable for storing centers of the particles
    Coordinates centers;
    // List of private methods that are needed
    // to process image
    void __process();
    void __detectPoints();
    void __filterResults();
    void __computeCenters();
    void __clearResults();
    bool isValidProto(const json&);
public:
    //setters
    void setImage(const cv::Mat&);
    void setParticleRadius(uint8_t);
    //getters
    uint8_t getRadius();
    cv::Mat getImage();
    std::vector<Points> getContours();
    Coordinates getCenters();
    //constructors
    ParticleDistinguisher() = default;
    void process();
    void reset();
    void setParams(const json&) override;
};


#endif //PARTICLEDISTINGUISHER_PARTICLEDISTINGUISHER_H
