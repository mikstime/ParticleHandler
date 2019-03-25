//
// Created by Михаил on 2019-03-25.
//

#ifndef PARTICLEHANDLER_SETTINGSHANDLER_H
#define PARTICLEHANDLER_SETTINGSHANDLER_H

#include "TYPES.h"
#include "FilterApplierSettinger.h"
#include "ParticleDistinguisherSettinger.h"
#include "PositionTrackerSettinger.h"
#include "PositionHandlerSettinger.h"
class SettingsHandler {
    //@TODO change declaration
    SettingsHandler();
public:
    static Settinger* getFAS();
    static Settinger* getPDS();
    static Settinger* getPTS();
    static Settinger* getPHS();
    static SettingsHandler* getInstance();
};


#endif //PARTICLEHANDLER_SETTINGSHANDLER_H
