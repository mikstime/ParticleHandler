
#include "PositionAnalyser.h"
#include "SettingsHandler.h"
typedef std::vector<cv::Point> Points;
void changeSettings();
int main() {

    PositionAnalyser* positionAnalyser = new PositionAnalyser;
    positionAnalyser->setParticleRadius(3);
    positionAnalyser->loadVideo("../test.avi");
    positionAnalyser->setBorders(1, 1000);
    positionAnalyser->ProcessVideo();
    positionAnalyser->savePositionList("../logs.txt");
    return 0;
}