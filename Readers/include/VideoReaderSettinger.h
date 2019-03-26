//
// Created by Михаил on 2019-03-26.
//

#ifndef PARTICLEHANDLER_VIDEOREADERSETTINGER_H
#define PARTICLEHANDLER_VIDEOREADERSETTINGER_H

#include "Settinger.h"
#include "VideoReader.h"
class VideoReaderSettinger: public Settinger {
public:
    void setBorders(VideoReader*, uint16_t, uint16_t);
    void setUpperBorder(VideoReader*, uint16_t);
    void setLowerBorder(VideoReader*, uint16_t);
};


#endif //PARTICLEHANDLER_VIDEOREADERSETTINGER_H
