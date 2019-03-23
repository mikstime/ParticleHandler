//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_POSITIONTRACKER_H
#define PARTICLEDISTINGUISHER_POSITIONTRACKER_H

#include "opencv2/core/core.hpp"
#include "vector"
#include "TYPES.h"
#include "PositionLogger.h"


class PositionTracker {
    uint8_t particleRadius;
    Coordinates currentCenters, nextCenters;
    std::vector<Coordinates> unitedCenters;

    u_int16_t currentId;
    void __clearResults();
public:
    void setRadius(uint8_t);
    uint8_t getRadius();
    void setCurrentCenters(Coordinates);
    void setNextCenters(Coordinates);
    void setCenters(Coordinates, Coordinates);
    std::vector<Coordinates> getUnitedCenters();
    void analyse();
    void reset();
};


#endif //PARTICLEDISTINGUISHER_POSITIONTRACKRE_H
