
#include <BandWFilter.h>
#include <iostream>
#include "PositionAnalyser.h"
#include "TYPES.h"
int main() {
    PositionAnalyser* positionAnalyser = new PositionAnalyser;
    positionAnalyser->setParticleRadius(5);
    positionAnalyser->loadVideo("../test.avi");
    positionAnalyser->setBorders(1,3);
    positionAnalyser->ProcessVideo();
    positionAnalyser->savePositionList("../logs.txt");
    return 0;
}