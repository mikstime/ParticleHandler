
#include <iostream>
#include "PositionAnalyser.h"
#include "SettingsHandler.h"
#include "EmphasizeFilter.h"
#include "GrayScaleFilter.h"
#include <PositionTracker.h>
#include <PositionHandler.h>
#include "Loader.h"
typedef std::vector<cv::Point> Points;
template <typename T>
LoadableObjectBase* createInstance() {return new T;}
int main() {
    auto pa = new PositionAnalyser;

    std::map<std::string, LoadableObjectBase*(*)()> TypeList;
    TypeList["GrayScaleFilter"] = &createInstance<GrayScaleFilter>;
    TypeList["EmphasizeFilter"] = &createInstance<EmphasizeFilter>;
    TypeList["ParticleDistinguisher"] = &createInstance<ParticleDistinguisher>;
    TypeList["VideoReader"] = &createInstance<VideoReader>;
    TypeList["PositionHandler"] = &createInstance<PositionHandler>;
    TypeList["PositionTracker"] = &createInstance<PositionTracker>;
    Loader* loader = Loader::instance();
    loader->setObjectTypes(TypeList);
    auto ObjList = loader->parseObjects("../test.json");
    for(int i = 0; i < ObjList.size(); i++) {
        std::cout << ObjList[i].getObjectTypeName() << '\n';
    }
    //@TODO get rid of other settingers
    auto FAS = (FilterApplierSettinger*) SettingsHandler::getFAS();

    auto fh = pa->getFrameHandler();
    auto fa = fh->getImageHandler()->getFilterApplier();
    auto ph = pa->getPositionHandler();
    auto pt = fh->getPositionTracker();

    FAS->addFilter(fa, (Filter*)ObjList[0].getObject());
    FAS->addFilter(fa, (Filter*)ObjList[1].getObject());
    fh->setParticleDistinguisher((ParticleDistinguisher*)ObjList[2].getObject());
    pa->setVideoReader((VideoReader*)ObjList[3].getObject());
    pa->setPositionHandler((PositionHandler*)ObjList[4].getObject());
    fh->setPositionTracker((PositionTracker*)ObjList[5].getObject());

    pa->loadVideo("../test.avi");
    pa->ProcessVideo();
    pa->savePositionList("../logs.txt");
    return 0;
}