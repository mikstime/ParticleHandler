//
// Created by Михаил on 2019-03-16.
//

#include "PositionTracker.h"
using namespace mbtsky;
using namespace nlohmann;
void PositionTracker::analyse(const Coordinates&currentCenters_,
                              const Coordinates&nextCenters_,
                              std::vector<Coordinates>& unitedCenters_) {

    Coordinate center1, center2;

    double maxDistSquared = 4 * particleRadius * particleRadius;
    // for avoiding analyse of processed points
    std::map<int, bool> concatNext;
    currentCenters = currentCenters_;
    nextCenters = nextCenters_;
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
    // assign result to unitedCenters_
    unitedCenters_ = unitedCenters;
    __clearResults();
}
void PositionTracker::__clearResults() {
    currentCenters.clear();
    nextCenters.clear();
    unitedCenters.clear();
}
void PositionTracker::reset() {
    __clearResults();
}
void PositionTracker::setParams(const nlohmann::json &objDesc) {
    if(!isValidProto(objDesc))
        return;
    particleRadius = objDesc["particleRadius"].get<uint8_t>();
}
bool PositionTracker::isValidProto(const nlohmann::json &objDesc) {
    return objDesc["particleRadius"].type() == json::value_t::number_unsigned;
}