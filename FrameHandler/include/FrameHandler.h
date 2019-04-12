//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_FRAMEHANDLER_H
#define PARTICLEDISTINGUISHER_FRAMEHANDLER_H


#include "ParticleDistinguisher.h"
#include "PositionTracker.h"
#include "TYPES.h"
#include <FilterApplier.h>
#include <PositionHandler.h>
typedef std::vector<double> ParamList;
namespace mbtsky {
    using namespace mbtsky;

    class FrameHandler {
        FilterApplier* filterApplier;
        PositionTracker *positionTracker;
        ParticleDistinguisher *particleDistinguisher;

        cv::Mat currentFrame, nextFrame;

        Coordinates currentCenters, nextCenters;
        std::vector<Coordinates> centerPositionChange;

        void __process();

        void __filter();

        void __distinguish();

        void __track();

        void __setup();

        void __clearResults();

    public:
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

        void ProcessFrames();

        FrameHandler();

        void reset();

        //
        FilterApplier* getFilterApplier() {
            return filterApplier;
        }

        void setParticleDistinguisher(ParticleDistinguisher * pd) {
            particleDistinguisher = pd;
        };

        ParticleDistinguisher *getParticleDistinguisher() {
            return particleDistinguisher;
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
