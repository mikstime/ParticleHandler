//
// Created by Михаил on 2019-03-17.
//

#ifndef PARTICLEDISTINGUISHER_POSITIONLOGGER_H
#define PARTICLEDISTINGUISHER_POSITIONLOGGER_H

#include "Path.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "TYPES.h"
#include "PositionLogger.h"
namespace mbtsky {
    class PositionLogger : public Path {

    public:
        //*********************************************************************
        // saveCoordinates
        // @param coordinatesList - list of coordinates to be stored
        //*********************************************************************
        void saveCoordinates(std::vector<Coordinates> coordinatesList);

    };

}

#endif //PARTICLEDISTINGUISHER_POSITIONLOGGER_H
