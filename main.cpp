
#include <iostream>
#include "PositionAnalyser.h"
#include "SettingsHandler.h"
#include "EmphasizeFilter.h"
#include "GrayScaleFilter.h"
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

    //@TODO get rid of other settingers
    auto PTS = (PositionTrackerSettinger*) SettingsHandler::getPTS();
    auto PHS = (PositionHandlerSettinger*) SettingsHandler::getPHS();
    auto FAS = (FilterApplierSettinger*) SettingsHandler::getFAS();
    auto VRS = (VideoReaderSettinger*) SettingsHandler::getVRS();

    auto fh = pa->getFrameHandler();
    auto fa = fh->getImageHandler()->getFilterApplier();
    auto ph = pa->getPositionHandler();
    auto pt = fh->getPositionTracker();
    auto vr = pa->getVideoReader();

    Loader* loader = Loader::instance();

    loader->setObjectTypes(TypeList);
    auto ObjList = loader->parseObjects("../test.json");
    PHS->setParticleRadius(ph, 10);
    PTS->setRadius(pt, 10);
    fh->setParticleDistinguisher((ParticleDistinguisher*)ObjList[2].getObject());
    FAS->addFilter(fa, (Filter*)ObjList[0].getObject());
    FAS->addFilter(fa, (Filter*)ObjList[1].getObject());

    VRS->setBorders(vr, 1, 10);
    pa->loadVideo("../test.avi");
    pa->ProcessVideo();
    pa->savePositionList("../logs.txt");
    return 0;
}