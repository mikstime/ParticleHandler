//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_FRAMEHANDLER_H
#define PARTICLEDISTINGUISHER_FRAMEHANDLER_H


#include "ParticleRecognizer.h"
#include "PositionHandler.h"
#include "PositionTracker.h"
#include "FilterApplier.h"
#include "TYPES.h"
typedef std::vector<double> ParamList;
namespace mbtsky {
    using namespace mbtsky;

    class FrameHandler {
        //*********************************************************************
        // filterApplier is used for applying filters =)
        //*********************************************************************
        FilterApplier* filterApplier;

        //*********************************************************************
        // particleRecognizer is used for computing position of centers
        // for each particle in both frames
        //*********************************************************************
        ParticleRecognizer *particleRecognizer;

        //*********************************************************************
        // positionTracker tracks position change between two frames
        //*********************************************************************
        PositionTracker *positionTracker;

        //*********************************************************************
        // Store two frames for processing
        //*********************************************************************
        cv::Mat currentFrame, nextFrame;

        //*********************************************************************
        // Coordinates of centers for both frames
        //*********************************************************************
        Coordinates currentCenters, nextCenters;

        //*********************************************************************
        // Corresponding positions for the particles from the second frame to
        // the positions in the first one
        //*********************************************************************
        std::vector<Coordinates> centerPositionChange;
        //*********************************************************************
        // __process
        // Combination of __filter, __distinguish and __track
        //*********************************************************************
        void __process();

        //*********************************************************************
        // __filter
        // Use filters and filterApplier for processing image
        //*********************************************************************
        void __filter();

        //*********************************************************************
        // __distinguish
        // Use particleRecognizer for detecting particles
        //*********************************************************************
        void __distinguish();

        //*********************************************************************
        // __track
        // Use positionTracker for tracking motion of particles
        //*********************************************************************
        void __track();

        //*********************************************************************
        // __setup
        // setup modules
        //*********************************************************************
        void __setup();

        //*********************************************************************
        // __clearResults
        // remove all stored data
        //*********************************************************************
        void __clearResults();

    public:

        //*********************************************************************
        // ProcessFrames
        // @param first and second frames
        // @param result - variable for assigning the result of processing
        //*********************************************************************
        void ProcessFrames(
                const cv::Mat& firstFrame,
                const cv::Mat& secondFrame,
                std::vector<Coordinates>& result
         );

        //*********************************************************************
        // Default constructor
        //*********************************************************************
        FrameHandler();

        //*********************************************************************
        // Copy constructor
        //*********************************************************************
        FrameHandler(FrameHandler& fh);

        //*********************************************************************
        // reset
        // Clear the results and reset all used modules
        //*********************************************************************
        void reset();
        FilterApplier* getFilterApplier() {
            return filterApplier;
        }

        //*********************************************************************
        // setParticleRecognizer
        //*********************************************************************
        void setParticleRecognizer(ParticleRecognizer * pd) {
            particleRecognizer = pd;
        };

        //*********************************************************************
        // getParticleRecognizer
        // @result pointer to particleRecognizer
        //*********************************************************************
        ParticleRecognizer *getParticleRecognizer() {
            return particleRecognizer;
        };

        //*********************************************************************
        // setPositionTracker
        //*********************************************************************
        void setPositionTracker(PositionTracker *pt) {
            positionTracker = pt;
        };

        //*********************************************************************
        // getPositionTracker
        // @result pointer to positionTracker
        //*********************************************************************
        PositionTracker *getPositionTracker() {
            return positionTracker;
        };

    };
}
#endif //PARTICLEDISTINGUISHER_FRAMEHANDLER_H
