//
// Created by Mikhail on 2019-04-13.
//

#ifndef PARTICLEHANDLER_OBJECTMANAGER_H
#define PARTICLEHANDLER_OBJECTMANAGER_H

#include "PositionAnalyser.h"
// FrameHandler, PositionAnalyser, FilterApplier,
// Filter, ParticleRecognizer, PositionTracker
// VideoReader, PositionHandler
#include <Loader.h>
#include <TYPES.h>
namespace mbtsky {
    using namespace mbtsky;
    class ObjectManager {
        //*********************************************************************
        // Used for storing inited filters
        //*********************************************************************
        std::vector<filters::Filter*> FilterList;

        //*********************************************************************
        // Used for storing inited(lastly) ParticleRecognizer
        //*********************************************************************
        ParticleRecognizer* particleRecognizer;

        //*********************************************************************
        // Used for storing inited(last) PositionTracker
        //*********************************************************************
        PositionTracker* positionTracker;

        //*********************************************************************
        // Used for storing inited(last) VideoReader
        //*********************************************************************
        VideoReader* videoReader;

        //*********************************************************************
        // Used for storing inited(last) PositionHandler
        //*********************************************************************
        PositionHandler* positionHandler;

        //*********************************************************************
        // parseFilter
        // converts object to Filter and appends to FilterList
        //*********************************************************************
        void parseFilter(LoadableObjectBase*filter) {

            FilterList.push_back((filters::Filter*)filter);
        };

        //*********************************************************************
        // parseParticleRecognizer
        // converts object to ParticleRecognizer and stores it
        //*********************************************************************
        void parseParticleRecognizer(LoadableObjectBase*pr) {
            particleRecognizer = (ParticleRecognizer*)pr;
        }

        //*********************************************************************
        // parsePositionTracker
        // converts object to PositionTracker and stores it
        //*********************************************************************
        void parsePositionTracker(LoadableObjectBase*pt) {
            positionTracker = (PositionTracker*)pt;
        };

        //*********************************************************************
        // parseVideoReader
        // converts object to VideoReader and stores it
        //*********************************************************************
        void parseVideoReader(LoadableObjectBase*vr) {
            videoReader = (VideoReader*)vr;
        };

        //*********************************************************************
        // parsePositionHandler
        // converts object to PositionHandler and stores it
        //*********************************************************************
        void parsePositionHandler(LoadableObjectBase*ph) {
            positionHandler = (PositionHandler*)ph;
        };
        ObjectManager() = default;
    public:

        //*********************************************************************
        // parseObjects
        // @param positionAnalyser - positionAnalyser and list of objects to init
        //*********************************************************************
        void parseObjects(PositionAnalyser* positionAnalyser,
                std::vector<Loader::Result>&);

        //*********************************************************************
        // Singleton structure
        //*********************************************************************
        static ObjectManager* instance() {
            static ObjectManager* instance = new ObjectManager();
            return instance;
        }
    };
}


#endif //PARTICLEHANDLER_OBJECTMANAGER_H
