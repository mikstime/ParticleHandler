//
// Created by Михаил on 2019-03-17.
//

#ifndef PARTICLEDISTINGUISHER_POSITIONLOGGER_H
#define PARTICLEDISTINGUISHER_POSITIONLOGGER_H

#include <opencv2/core/core.hpp>
#include "Path.h"
#include <vector>
typedef std::vector<cv::Point> Points;

class PositionLogger: public Path {

public:
    void saveCoordinates(std::vector<Points>);
    void reset();
};


#endif //PARTICLEDISTINGUISHER_POSITIONLOGGER_H
