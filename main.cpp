
#include <iostream>
#include "EmphasizeFilter.h"
#include "GreyScaleFilter.h"
#include <ObjectManager.h>
typedef std::vector<cv::Point> Points;
using namespace mbtsky;
template <typename T>
LoadableObjectBase* createInstance() {return new T;}
int main() {
    std::map<std::string, LoadableObjectBase*(*)()> TypeList;

    Loader* loader = Loader::instance();
    TypeList["VideoReader"] = &createInstance<VideoReader>;
    TypeList["GreyScaleFilter"] = &createInstance<filters::GreyScaleFilter>;
    TypeList["EmphasizeFilter"] = &createInstance<filters::EmphasizeFilter>;
    TypeList["PositionHandler"] = &createInstance<PositionHandler>;
    TypeList["PositionTracker"] = &createInstance<PositionTracker>;
    TypeList["ParticleRecognizer"] = &createInstance<ParticleRecognizer>;
    loader->setObjectTypes(TypeList);

    ObjectManager* om = ObjectManager::instance();
    auto positionAnalyser = new PositionAnalyser;

    auto ObjList = loader->parseObjects("../test.json");
    om->parseObjects(positionAnalyser, ObjList);
    positionAnalyser->loadVideo("../test.avi");
    positionAnalyser->ProcessVideo();
    positionAnalyser->savePositionList("../logs.txt");
    return 0;
}