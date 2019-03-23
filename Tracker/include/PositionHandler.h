//
// Created by Михаил on 2019-03-18.
//

#ifndef FRAMEHANDLER_POSITIONHANDLER_H
#define FRAMEHANDLER_POSITIONHANDLER_H

#include <vector>
#include <map>
#include "opencv2/core/core.hpp"
typedef std::vector<cv::Point> Points;

//@TODO on __combinePositions() previous results is updated by currentResult. CurrentResult.clear();
class PositionHandler {
    uint8_t particleRadius;
    bool __isCombined = false;
    std::vector<Points> processedPositions, positionsToProcess;
    std::map<int, bool> processedFound;
    std::map<int, bool > toProcessFound;
    void __setup();
    void __combinePositions();
    //Do some things after combining positionLists
    void __combined();
    void __reset();
public:
    void setParticleRadius(uint8_t);
    void setPositionsToProcess(std::vector<Points>);
    void combine();
    std::vector<Points> getProcessedPositions();
    void reset();
};


#endif //FRAMEHANDLER_POSITIONHANDLER_H
