//
// Created by Михаил on 2019-03-25.
//

#ifndef PARTICLEHANDLER_SETTINGSHANDLER_H
#define PARTICLEHANDLER_SETTINGSHANDLER_H

#include "TYPES.h"
#include "FilterApplierSettinger.h"
class SettingsHandler {
    //@TODO change declaration
    SettingsHandler();
public:
    static Settinger* getFAS();
    static SettingsHandler* getInstance();
};


#endif //PARTICLEHANDLER_SETTINGSHANDLER_H
