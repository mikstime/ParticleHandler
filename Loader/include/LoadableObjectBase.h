//
// Created by Михаил on 2019-04-10.
//

#ifndef PREVIEWHANDLER_LOADABLEOBJECTBASE_H
#define PREVIEWHANDLER_LOADABLEOBJECTBASE_H

#include <json.hpp>
class LoadableObjectBase {
public:
    virtual void setParams(const nlohmann::json&) = 0;
};


#endif //PREVIEWHANDLER_LOADABLEOBJECTBASE_H
