//
// Created by Михаил on 2019-03-25.
//

#include "PositionHandlerSettinger.h"
#include "PositionHandler.h"
void PositionHandlerSettinger::setParticleRadius(
        PositionHandler *positionHandler, uint8_t particleRadius) {
    positionHandler->setParticleRadius(particleRadius);
}