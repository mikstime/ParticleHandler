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

    void __clearResults();

protected:
    void setRadius(uint8_t);
public:
    uint8_t getRadius();
    void setCurrentCenters(const Coordinates&);
    void setNextCenters(const Coordinates&);
    void setCenters(const Coordinates&, const Coordinates&);
    std::vector<Coordinates> getUnitedCenters();
    void analyse();
    void reset();
    friend class PositionTrackerSettinger;
};


#endif //PARTICLEDISTINGUISHER_POSITIONTRACKRE_H
