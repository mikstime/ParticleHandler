//
// Created by Mikhail on 2019-04-13.
//

#include "ObjectManager.h"

using namespace mbtsky;

void ObjectManager::parseObjects(PositionAnalyser* positionAnalyser,
        std::vector<mbtsky::Loader::Result>& listOfObjects) {

    bool parsed[5] = {false};

    for(mbtsky::Loader::Result obj : listOfObjects) {
        if(~obj.getObjectTypeName().rfind("Filter")) {
            parseFilter(obj.getObject());
            parsed[0] = true;// init filters
        } else if(~obj.getObjectTypeName().rfind("ParticleRecognizer")) {
            parseParticleRecognizer(obj.getObject());
            parsed[1] = true;// init particleRecognizer
        } else if(~obj.getObjectTypeName().rfind("PositionTracker")) {
            parsePositionTracker(obj.getObject());
            parsed[2] = true;// init positionTracker
        } else if(~obj.getObjectTypeName().rfind("VideoReader")) {
            parseVideoReader(obj.getObject());
            parsed[3] = true;// init videoReader
        } else if(~obj.getObjectTypeName().rfind("PositionHandler")) {
            parsePositionHandler(obj.getObject());
            parsed[4] = true;// init positionHandler
        }
    }

    auto frameHandler = positionAnalyser->getFrameHandler();
    auto filterApplier = frameHandler->getFilterApplier();

    // if module is inited append it.
    // Otherwise default one will be used
    if(parsed[0])
        positionAnalyser->setVideoReader(videoReader);
    if(parsed[1])
        positionAnalyser->setPositionHandler(positionHandler);
    if(parsed[2])
        frameHandler->setParticleRecognizer(particleRecognizer);
    if(parsed[3])
        frameHandler->setPositionTracker(positionTracker);
    if(parsed[4])
        filterApplier->addFilters(FilterList);

}