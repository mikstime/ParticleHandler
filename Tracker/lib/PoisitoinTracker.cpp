//
// Created by Михаил on 2019-03-16.
//

#include "PositionTracker.h"
#include "opencv2/core/core.hpp"
#include "vector"
#include <map>
#include "TYPES.h"

void PositionTracker::setCenters(Coordinates currentCenters_, Coordinates nextCenters_) {
    __clearResults();
    currentCenters = currentCenters_;
    nextCenters = nextCenters_;
}
void PositionTracker::setCurrentCenters(Coordinates currentCenters_) {
    currentCenters = currentCenters_;
}
void PositionTracker::setNextCenters(Coordinates nextCenters_) {
    nextCenters = nextCenters_;
}

void PositionTracker::analyse() {

    Point center1, center2;
    // Find the closest particle in O(n^2)
    //@TODO Try to  reduce to O(nlogn)
    //@TODO Use linked lists for quick deletion of used particles
    //@TODO add check if particle already tracked
    double maxDistSquared = 5 * 4 * particleRadius * particleRadius;
    std::map<int, bool> concatNext;
    for(uint16_t i = 0; i < currentCenters.size(); i++) {
        for(uint16_t j = 0; j < nextCenters.size(); j++) {
            // Skip if already concat to avoid duplicating
            // If no match found
            if(concatNext[j] == true)
                continue;
            center1 = currentCenters[i];
            center2 = nextCenters[j];
            // Only x and y because particles are two definitional
            double dx = center1.x - center2.x;
            double dy = center1.y - center2.y;
            //
            double distanceSquared = dx * dx + dy * dy;
            Coordinates united;
            // If distance between centers is less than size of a particle
            // Movement can be detected and united
            if(distanceSquared < maxDistSquared) {
                united.push_back(center1);
                united.push_back(center2);
                unitedCenters.push_back(united);
                united.clear();
                concatNext[j] = true;
                break;
            }
        }
    }
    concatNext.clear();
}
void PositionTracker::setRadius(uint8_t particleRadius_) {
    particleRadius = particleRadius_;
}
uint8_t PositionTracker::getRadius() {
    return particleRadius;
}
std::vector<Coordinates> PositionTracker::getUnitedCenters() {
    return unitedCenters;
}
void PositionTracker::__clearResults() {
    currentCenters.clear();
    nextCenters.clear();
    unitedCenters.clear();
    currentId = 0;
}
void PositionTracker::reset() {
    __clearResults();
}