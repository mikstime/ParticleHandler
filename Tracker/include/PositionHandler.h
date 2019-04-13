//
// Created by Михаил on 2019-03-18.
//

#ifndef FRAMEHANDLER_POSITIONHANDLER_H
#define FRAMEHANDLER_POSITIONHANDLER_H

#include <vector>
#include <map>
#include "opencv2/core/core.hpp"
#include "TYPES.h"
#include <LoadableObjectBase.h>
#include <json.hpp>
namespace mbtsky {
    class PositionHandler : public LoadableObjectBase {
        //*********************************************************************
        // particleRadius - radius of the particle
        //*********************************************************************
        uint8_t particleRadius;

        //*********************************************************************
        // indicator if positions processed
        //*********************************************************************
        bool __isCombined = false;
        std::vector<Coordinates> processedPositions, positionsToProcess;
        std::map<int, bool> processedFound;
        std::map<int, bool> toProcessFound;

        void __combinePositions();

        //Do some things after combining positionLists
        void __combined();

        void __reset();

        bool isValidProto(const nlohmann::json &);

    public:
        //*********************************************************************
        // Default constructor
        //*********************************************************************
        PositionHandler() = default;

        //*********************************************************************
        // Copy constructor
        //*********************************************************************
        PositionHandler(PositionHandler&);

        //*********************************************************************
        // setParticleRadius
        //*********************************************************************
        void setParticleRadius(uint8_t particleRadius_) {
            particleRadius = particleRadius_;
        };

        //*********************************************************************
        // setPositionsToProcess
        //*********************************************************************
        void setPositionsToProcess(const std::vector<Coordinates> & ptp);

        //*********************************************************************
        // combine
        // stick positions together
        //*********************************************************************
        void combine();

        //*********************************************************************
        // getProcessedPositions
        // @result vector of resulting coordinates
        //*********************************************************************
        std::vector<Coordinates>& getProcessedPositions() {
            return processedPositions;
        };

        //*********************************************************************
        // reset
        // reset all modules and remove stored data
        //*********************************************************************
        void reset();

        //*********************************************************************
        // setParams
        // parse json data to object
        //*********************************************************************
        void setParams(const nlohmann::json &) override;
    };
}


#endif //FRAMEHANDLER_POSITIONHANDLER_H
