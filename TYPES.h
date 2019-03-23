//
// Created by Михаил on 2019-03-24.
//

#ifndef PARTICLEHANDLER_TYPES_H
#define PARTICLEHANDLER_TYPES_H

#include <opencv2/core/types.hpp>
#include <vector>

typedef cv::Point3_<uint8_t> Pixel;

typedef cv::Point Point;
typedef std::vector<Point> Points;

typedef cv::Point2d Coordinate;
typedef std::vector<Coordinate> Coordinates;

#endif //PARTICLEHANDLER_TYPES_H
