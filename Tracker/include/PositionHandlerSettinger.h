//
// Created by Михаил on 2019-03-25.
//

#ifndef PARTICLEHANDLER_POSITIONHANDLERSETTINGER_H
#define PARTICLEHANDLER_POSITIONHANDLERSETTINGER_H

#include "PositionHandler.h"
#include "Settinger.h"
class PositionHandlerSettinger : public Settinger {
public:
    void setParticleRadius(PositionHandler *, uint8_t);
};


#endif //PARTICLEHANDLER_POSITIONHANDLERSETTINGER_H
