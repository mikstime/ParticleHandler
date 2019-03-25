//
// Created by Михаил on 2019-03-25.
//

#include "PositionTrackerSettinger.h"
void PositionTrackerSettinger::setRadius(
        PositionTracker * positionTracker, uint8_t particleRadius) {
    positionTracker->setRadius(particleRadius);
}