//
// Created by Михаил on 2019-03-26.
//

#ifndef PARTICLEHANDLER_EMPHASIZEFILTERSETTINGER_H
#define PARTICLEHANDLER_EMPHASIZEFILTERSETTINGER_H

#include "Settinger.h"
#include "EmphasizeFilter.h"
class EmphasizeFilterSettinger: public Settinger {
public:
    void setRadius(EmphasizeFilter*, uint8_t);
    void setLambda(EmphasizeFilter*, uint8_t);
};


#endif //PARTICLEHANDLER_EMPHASIZEFILTERSETTINGER_H
