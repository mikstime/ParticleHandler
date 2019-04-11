//
// Created by Михаил on 2019-03-25.
//

#ifndef PARTICLEHANDLER_SETTINGSHANDLER_H
#define PARTICLEHANDLER_SETTINGSHANDLER_H

#include "TYPES.h"
#include "FilterApplierSettinger.h"
#include "PositionTrackerSettinger.h"
#include "PositionHandlerSettinger.h"
#include "VideoReaderSettinger.h"
class SettingsHandler {
    SettingsHandler();
public:
    static Settinger* getFAS();
    static Settinger* getPTS();
    static Settinger* getPHS();
    static Settinger* getVRS();
    static SettingsHandler* getInstance();
};


#endif //PARTICLEHANDLER_SETTINGSHANDLER_H
