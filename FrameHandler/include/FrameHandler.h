//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_FRAMEHANDLER_H
#define PARTICLEDISTINGUISHER_FRAMEHANDLER_H


#include "ParticleRecognizer.h"
#include "PositionTracker.h"
#include "TYPES.h"
#include <FilterApplier.h>
#include <PositionHandler.h>
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
        // store two frames for processing
        //*********************************************************************
        cv::Mat currentFrame, nextFrame;

        //*********************************************************************
        // coordinates of centers for both frames
        //*********************************************************************
        Coordinates currentCenters, nextCenters;

        //*********************************************************************
        // corresponding positions for the particles from the second frame to
        // the positions in the first one
        //*********************************************************************
        std::vector<Coordinates> centerPositionChange;

        void __process();

        void __filter();

        void __distinguish();

        void __track();

        void __setup();

        void __clearResults();

    public:

        void ProcessFrames();

        FrameHandler();

        void reset();

        void setFrames(const cv::Mat &, const cv::Mat &);

        void setCurrentFrame(const cv::Mat &);

        void setNextFrame(const cv::Mat &);

        cv::Mat getCurrentFrame() {
            return currentFrame;
        };

        cv::Mat getNextFrame() {
            return nextFrame;
        };

        std::vector<Coordinates> getPositionChange() {
            return centerPositionChange;
        };
        //
        FilterApplier* getFilterApplier() {
            return filterApplier;
        }

        void setParticleRecognizer(ParticleRecognizer * pd) {
            particleRecognizer = pd;
        };

        ParticleRecognizer *getParticleRecognizer() {
            return particleRecognizer;
        };

        void setPositionTracker(PositionTracker *pt) {
            positionTracker = pt;
        };

        PositionTracker *getPositionTracker() {
            return positionTracker;
        };

    };
}
#endif //PARTICLEDISTINGUISHER_FRAMEHANDLER_H
