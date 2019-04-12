//
// Created by Михаил on 2019-03-24.
//

#ifndef PARTICLEHANDLER_TYPES_H
#define PARTICLEHANDLER_TYPES_H

#include <opencv2/core/types.hpp>
#include <vector>
//*****************************************************************************
// for storing image pixels
//*****************************************************************************
typedef cv::Point3_<uint8_t> Pixel;
//*****************************************************************************
// coordinate of pixel in image
//*****************************************************************************
typedef cv::Point Point;
//*****************************************************************************
// list of points
//*****************************************************************************
typedef std::vector<Point> Points;
//*****************************************************************************
// coordinate of particle after distinguishing
//*****************************************************************************
typedef cv::Point2d Coordinate;
//*****************************************************************************
// list of coordinates
//*****************************************************************************
typedef std::vector<Coordinate> Coordinates;

#endif //PARTICLEHANDLER_TYPES_H
