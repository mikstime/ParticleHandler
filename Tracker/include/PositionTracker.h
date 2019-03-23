//
// Created by Михаил on 2019-03-16.
//

#ifndef PARTICLEDISTINGUISHER_POSITIONTRACKER_H
#define PARTICLEDISTINGUISHER_POSITIONTRACKER_H

#include "opencv2/core/core.hpp"
#include "vector"

#include "PositionLogger.h"

typedef std::vector<cv::Point> Points;

class PositionTracker {
    uint8_t particleRadius;
    Points currentCenters, nextCenters;
    std::vector<Points> unitedCenters;

    u_int16_t currentId;
    void __clearResults();
public:
    void setRadius(uint8_t);
    uint8_t getRadius();
    void setCurrentCenters(Points);
    void setNextCenters(Points);
    void setCenters(Points, Points);
    std::vector<Points> getUnitedCenters();
    void analyse();
    void reset();
};


#endif //PARTICLEDISTINGUISHER_POSITIONTRACKRE_H
