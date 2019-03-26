
#include "PositionAnalyser.h"
#include "SettingsHandler.h"
#include "EmphasizeFilter.h"
#include "BandWFilter.h"
typedef std::vector<cv::Point> Points;
void changeSettings();
int main() {
    auto pa = new PositionAnalyser;

    auto PDS = (ParticleDistinguisherSettinger*) SettingsHandler::getPDS();
    auto PTS = (PositionTrackerSettinger*) SettingsHandler::getPTS();
    auto PHS = (PositionHandlerSettinger*) SettingsHandler::getPHS();
    auto FAS = (FilterApplierSettinger*) SettingsHandler::getFAS();
    auto EFS = (EmphasizeFilterSettinger*) SettingsHandler::getEFS();
    auto VRS = (VideoReaderSettinger*) SettingsHandler::getVRS();

    auto fh = pa->getFrameHandler();
    auto fa = fh->getImageHandler()->getFilterApplier();
    auto pd = fh->getParticleDistinguisher();
    auto ph = pa->getPositionHandler();
    auto pt = fh->getPositionTracker();
    auto vr = pa->getVideoReader();

    Filter* blackAndWhiteFilter = new BandWFilter;
    Filter* emphasizeFilter = new EmphasizeFilter;
    EFS->setRadius((EmphasizeFilter *)emphasizeFilter, 5);
    EFS->setLambda((EmphasizeFilter *)emphasizeFilter, 7);

    PDS->setParticleRadius(pd, 5);
    PHS->setParticleRadius(ph, 10);
    PTS->setRadius(pt, 10);

    FAS->addFilter(fa, blackAndWhiteFilter);
    FAS->addFilter(fa, emphasizeFilter);

    VRS->setBorders(vr, 1, 10);

    pa->loadVideo("../test.avi");
    pa->ProcessVideo();
    pa->savePositionList("../logs.txt");
    return 0;
}