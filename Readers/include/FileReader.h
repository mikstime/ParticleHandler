//
// Created by Михаил on 2019-03-17.
//

#ifndef VIDEOREADER_FILEREADER_H
#define VIDEOREADER_FILEREADER_H

#include <string>
#include "Path.h"

using std::string;
class FileReader: public Path {
    virtual void readFile() = 0;
};


#endif //VIDEOREADER_FILEREADER_H
