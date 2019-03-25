//
// Created by Михаил on 2019-03-25.
//

#ifndef PARTICLEHANDLER_PARTICLEDISTINGUISHERSETTINGER_H
#define PARTICLEHANDLER_PARTICLEDISTINGUISHERSETTINGER_H

#include "Settinger.h"
#include "ParticleDistinguisher.h"
class ParticleDistinguisherSettinger: public Settinger {
public:
    void setParticleRadius(ParticleDistinguisher*, uint8_t);
};


#endif //PARTICLEHANDLER_PARTICLEDISTINGUISHERSETTINGER_H
