//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_POSITIONTRACKER_H
#define PARTICLEDISTINGUISHER_POSITIONTRACKER_H

#include "opencv2/core/core.hpp"
#include <LoadableObjectBase.h>

#include <vector>
#include <map>

#include "TYPES.h"
#include <json.hpp>

namespace mbtsky {

    class PositionTracker : public LoadableObjectBase {
        //*********************************************************************
        // particleRadius is used for checking distance between coordinates
        //*********************************************************************
        uint8_t particleRadius;

        //*********************************************************************
        // positions to analyse
        //*********************************************************************
        Coordinates currentCenters, nextCenters;

        //*********************************************************************
        // result of tracking
        //*********************************************************************
        std::vector<Coordinates> unitedCenters;

        //*********************************************************************
        // __clearResult
        // Remove all stored data
        //*********************************************************************
        void __clearResults();

        //*********************************************************************
        // isValidProto
        // @param - json object
        // @result return true if objectDescriptor is correct
        //*********************************************************************
        bool isValidProto(const nlohmann::json &objDesc);

    public:

        //*********************************************************************
        // default constructor sets particleRadius to 1
        //*********************************************************************
        PositionTracker() { particleRadius = 1; };

        //*********************************************************************
        // setParticleRadius
        // set particle radius to mentioned one
        //*********************************************************************
        void setParticleRadius(uint8_t particleRadius_) {
            particleRadius = particleRadius_;
        };

        //*********************************************************************
        // getParticleRadius
        // @result return particle's radius
        //*********************************************************************
        uint8_t getParticleRadius() {
            return particleRadius;
        };

        //*********************************************************************
        // analyse
        // @param currentCenters - set current coordinates
        // @param nextCenters - set coordinates to process
        // @param unitedCenters - resulting array of tracked coordinates
        // perform tracking
        //*********************************************************************
        void analyse
                (const Coordinates &currentCenters_,
                 const Coordinates &nextCenters_,
                 std::vector<Coordinates> &unitedCenters);

        //*********************************************************************
        // reset
        // restore all values
        //*********************************************************************
        void reset();

        //*********************************************************************
        // setParams
        // @param objDesc
        // set params via json object
        //*********************************************************************
        void setParams(const nlohmann::json &objDesc) override;
    };
}


#endif //PARTICLEDISTINGUISHER_POSITIONTRACKRE_H
