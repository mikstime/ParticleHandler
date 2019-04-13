//
// Created by Михаил on 2019-03-18.
//

#include <iostream>
#include "PositionHandler.h"
#include "TYPES.h"
#include <json.hpp>
using namespace mbtsky;

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
    uint8_t positionsSize;
    // Compute how many copies must be added
    for(int j = 0; j < positionsToProcess.size(); j++) {
        if(toProcessFound[j]) {
            positionsSize = positionsToProcess[j].size();
            break;
        }
    }

    for (int i = 0; i < processedPositions.size(); i++) {
        if (!processedFound[i]) {
            uint16_t lastInd = processedPositions[i].size() - 1;

            for (int k = 0; k < positionsSize; k++)
                processedPositions[i].push_back(processedPositions[i][lastInd]);
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
void PositionHandler::__reset() {
    processedFound.clear();
    toProcessFound.clear();
}
void PositionHandler::reset() {
    __reset();
}
void PositionHandler::setParams(const nlohmann::json & objDesc) {
    if(!isValidProto(objDesc))
        return;
    particleRadius = objDesc["particleRadius"].get<uint8_t >();
}
bool PositionHandler::isValidProto(const nlohmann::json & objDesc) {
    return objDesc["particleRadius"].type() == nlohmann::json::value_t::number_unsigned;
}
PositionHandler::PositionHandler(mbtsky::PositionHandler &ph) {
    particleRadius = ph.particleRadius;
    __isCombined=  ph.__isCombined;
    processedPositions = ph.processedPositions;
    positionsToProcess = ph.positionsToProcess;
    processedFound = ph.processedFound;
    toProcessFound = ph.toProcessFound;
}