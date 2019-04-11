//
// Created by Михаил on 2019-03-25.
//

#include "SettingsHandler.h"
#include <iostream>

SettingsHandler::SettingsHandler() {

}
SettingsHandler* SettingsHandler::getInstance() {
    static SettingsHandler* INSTANCE = new SettingsHandler;
    return INSTANCE;
}
Settinger* SettingsHandler::getFAS() {
    static Settinger* filterApplierSettinger
    = new FilterApplierSettinger;
    return filterApplierSettinger;
}
Settinger* SettingsHandler::getPTS() {
    static Settinger* positionTrackerSettinger
    = new PositionTrackerSettinger;
    return positionTrackerSettinger;
}
Settinger* SettingsHandler::getPHS() {
    static Settinger* positionHandlerSettinger
    = new PositionHandlerSettinger;
    return positionHandlerSettinger;
}
Settinger* SettingsHandler::getVRS() {
    static Settinger* videoReaderSettinger = new VideoReaderSettinger;
    return videoReaderSettinger;
}