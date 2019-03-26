//
// Created by Михаил on 2019-03-18.
//

#include <iostream>
#include "PositionHandler.h"
#include "TYPES.h"
std::vector<Coordinates> PositionHandler::getProcessedPositions() {
    return processedPositions;
}
void PositionHandler::setPositionsToProcess(const std::vector<Coordinates>& positionsToProcess_) {
    positionsToProcess = positionsToProcess_;
    __isCombined = false;
    if(processedPositions.size() == 0) {
        processedPositions = positionsToProcess;
        __isCombined = true;
    }
}
void PositionHandler::__combinePositions() {
    // If distance between centers is larger than particle size movement cannot be detected
    uint32_t maxDistSquared = 4 * particleRadius * particleRadius;
    // Define nested loops limits
    uint16_t endLeft = processedPositions.size();
    uint16_t endRight = positionsToProcess.size();
    // For storing current points from left and right parts
    Coordinate leftPoint, rightPoint;
    for (uint16_t i = 0; i < endLeft; i++) {
        for (uint16_t j = 0; j < endRight; j++) {
            // If particle already processed just skip
            if (toProcessFound[j] == true)
                continue;
            // Computing distance from last left particle
            // to first left
            uint16_t last = processedPositions[i].size() - 1;
            uint16_t first = 0;
            leftPoint = processedPositions[i][last];
            rightPoint = positionsToProcess[j][first];
            // Compute coordinate difference
            uint16_t dx = leftPoint.x - rightPoint.x;
            uint16_t dy = leftPoint.y - rightPoint.y;
            //Calculate square of the distance for faster processing
            uint32_t distSquared = dx * dx + dy * dy;
            // If distance is less than maxDist, a movement can be detected
            if (distSquared < maxDistSquared) {
                // Update point's positions
                processedFound[i] = true;
                toProcessFound[j] = true;
                for (uint16_t ri = 0; ri < positionsToProcess[j].size(); ri++) {
                    processedPositions[i].push_back(positionsToProcess[j][ri]);
                }
                break;
            }
        }
    }
    // For each not detected particle copy previous values
    //@TODO refactor
    for (int i = 0; i < processedPositions.size(); i++) {
        if (!processedFound[i]) {
            uint16_t lastInd = processedPositions[i].size() - 1;
            for (int j = 0; j < positionsToProcess.size(); j++) {
                if (toProcessFound[j]) {
                    // To make all positions the same size
                    for (int k = 0; k < positionsToProcess[j].size(); k++)
                        processedPositions[i].push_back(processedPositions[i][lastInd]);
                    break;
                }
            }
        }
    }
    __reset();
}
void PositionHandler::__combined() {
    __isCombined = true;
    positionsToProcess.clear();
}
void PositionHandler::combine() {
    if(!__isCombined) {
        __combinePositions();
        __combined();
    }
}
void PositionHandler::setParticleRadius(uint8_t particleRadius_) {
    particleRadius = particleRadius_;
}
void PositionHandler::__reset() {
    processedFound.clear();
    toProcessFound.clear();
}
void PositionHandler::reset() {
    __reset();
}