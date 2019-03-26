//
// Created by Михаил on 2019-03-26.
//

#include "EmphasizeFilterSettinger.h"

void EmphasizeFilterSettinger::setRadius(
        EmphasizeFilter * emphasizeFilter, uint8_t radius) {
    emphasizeFilter->setRadius(radius);
}
void EmphasizeFilterSettinger::setLambda(
        EmphasizeFilter * emphasizeFilter, uint8_t lambda) {
    emphasizeFilter->setLambda(lambda);
}