//
// Created by Михаил on 2019-03-26.
//

#include "VideoReaderSettinger.h"
void VideoReaderSettinger::setLowerBorder(
        VideoReader *videoReader, uint16_t lowerBorder) {
    videoReader->setLowerBorder(lowerBorder);
}
void VideoReaderSettinger::setUpperBorder(
        VideoReader *videoReader, uint16_t upperBorder) {
    videoReader->setUpperBorder(upperBorder);
}
void VideoReaderSettinger::setBorders(
        VideoReader *videoReader, uint16_t lowerBorder, uint16_t upperBorder) {
    videoReader->setBorders(lowerBorder, upperBorder);
}