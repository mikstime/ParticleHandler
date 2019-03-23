//
// Created by Михаил on 2019-03-17.
//

#include <fstream>
#include <iostream>
#include "PositionLogger.h"
#include "TYPES.h"

void PositionLogger::saveCoordinates(std::vector<Coordinates> coordinates) {
    std::ofstream file(getPath(), std::ios::out | std::ios::binary);
    uint16_t numOfParticles = coordinates.size();
    uint16_t numOfPositions;
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
void PositionLogger::reset() {

}