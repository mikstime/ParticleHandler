//
// Created by Михаил on 2019-03-25.
//

#ifndef PARTICLEHANDLER_POSITIONTRACKERSETTINGER_H
#define PARTICLEHANDLER_POSITIONTRACKERSETTINGER_H

#include "Settinger.h"
#include "PositionTracker.h"

class PositionTrackerSettinger: public Settinger {
public:
    void setRadius(PositionTracker*, uint8_t);
};


#endif //PARTICLEHANDLER_POSITIONTRACKERSETTINGER_H
