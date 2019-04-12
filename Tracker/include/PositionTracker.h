//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_POSITIONTRACKER_H
#define PARTICLEDISTINGUISHER_POSITIONTRACKER_H

#include "opencv2/core/core.hpp"
#include "vector"
#include "TYPES.h"
#include "PositionLogger.h"
#include <LoadableObjectBase.h>
#include <json.hpp>
//@TODO replace PostionTracker with PositionHandler
class PositionTracker: public LoadableObjectBase {
    uint8_t particleRadius;
    Coordinates currentCenters, nextCenters;
    std::vector<Coordinates> unitedCenters;

    void __clearResults();

    bool isValidProto(const nlohmann::json&);
public:
    PositionTracker() = default;
    uint8_t getRadius();
    void setRadius(uint8_t);
    void setCurrentCenters(const Coordinates&);
    void setNextCenters(const Coordinates&);
    void setCenters(const Coordinates&, const Coordinates&);
    std::vector<Coordinates> getUnitedCenters();
    void analyse();
    void reset();

    void setParams(const nlohmann::json&);
};


#endif //PARTICLEDISTINGUISHER_POSITIONTRACKRE_H
