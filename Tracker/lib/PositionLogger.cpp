//
// Created by Михаил on 2019-03-17.
//

#include "PositionLogger.h"
using namespace mbtsky;

void PositionLogger::saveCoordinates(std::vector<Coordinates> coordinates) {
    // open(create) file for writing
    std::ofstream file(getPath(), std::ios::out | std::ios::binary);
    uint16_t numOfParticles = coordinates.size();
    uint16_t numOfPositions;
    // save coordinates
    for(uint16_t i = 0; i < numOfParticles;  i++) {
        numOfPositions = coordinates[i].size();
        file << i;
        for(uint16_t j = 0; j < numOfPositions; j++) {
            file << ' ' << coordinates[i][j].x << ' ' << coordinates[i][j].y;
        }
        file << '\n';
    }
    file.close();
}