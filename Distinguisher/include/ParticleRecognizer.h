//
// Created by Михаил on 2019-03-15.
//

#ifndef PARTICLEDISTINGUISHER_PARTICLEDISTINGUISHER_H
#define PARTICLEDISTINGUISHER_PARTICLEDISTINGUISHER_H

// Base object for loading json data
#include <LoadableObjectBase.h>
// Required openCV modules
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
//
#include "TYPES.h"
using nlohmann::json;
namespace mbtsky {
    class ParticleRecognizer : public LoadableObjectBase {
        //*************************************************************************
        // image - source image used for particle recognition
        //*************************************************************************
        cv::Mat image;
        //*************************************************************************
        // particleRadius is used for filtering results
        //*************************************************************************
        uint8_t particleRadius;
        //*************************************************************************
        // contours are used for storing filtered contours
        //*************************************************************************
        std::vector<Points> contours;
        //*************************************************************************
        // centers store center of each contour
        //*************************************************************************
        Coordinates centers;

        //*************************************************************************
        // __process
        // combines __detectPoints,
        // __detectPoints, __filterResults together
        //*************************************************************************
        void __process();

        //*************************************************************************
        // __detectPoints
        // detects all contors in the image
        //*************************************************************************
        void __detectPoints();

        //*************************************************************************
        // __filterResults
        // filer all the 'fake' contours.
        //*************************************************************************
        void __filterResults();

        //*************************************************************************
        // __computeCenters
        // compute center of masses for each contour
        //*************************************************************************
        void __computeCenters();

        //*************************************************************************
        // __clearResults
        // remove all stored data
        //*************************************************************************
        void __clearResults() {
            contours.clear();
            centers.clear();
        };

        bool isValidProto(const json &objDesc);

    public:
        //*************************************************************************
        // setParticleRadius
        // @param particleRadius - radius of the particle
        //*************************************************************************
        void setParticleRadius(uint8_t particleRadius_) {
            particleRadius = particleRadius_;
        };

        //*************************************************************************
        // getParticleRadius
        // @return radius of the particle
        //*************************************************************************
        uint8_t getParticleRadius() {
            return particleRadius;
        };

        //*************************************************************************
        // getContours
        // @return contour for each particle in the image
        // Computed for the last image.
        //*************************************************************************
        std::vector<Points> getContours() {
            return contours;
        };

        //*************************************************************************
        // getCenters
        // @return center of each particle.
        // Computed for the last image.
        //*************************************************************************
        Coordinates getCenters() {
            return centers;
        };

        //*************************************************************************
        // default constructor.
        // Sets particle's radius to 1
        //*************************************************************************
        ParticleRecognizer() { particleRadius = 1; };

        //*************************************************************************
        // Copy constructor
        //*************************************************************************
        ParticleRecognizer(ParticleRecognizer &o) {
            particleRadius = o.getParticleRadius();
        };

        //*************************************************************************
        // process
        // @param image - binary image in grayscale mode
        // Find contours and centers for particles in image
        // Particles are defined by theirs radius
        //*************************************************************************
        void process(const cv::Mat &image_);

        //*************************************************************************
        // reset
        // removes all stored values
        //*************************************************************************
        void reset() {
            __clearResults();
        };

        //*************************************************************************
        // setParams
        // @param Desctiptor in json format.
        // required data : particleRadius
        // sets particleRadius to mentioned in json
        //*************************************************************************
        void setParams(const json &objDesc) override;
    };
}

#endif //PARTICLEDISTINGUISHER_PARTICLEDISTINGUISHER_H
