//
// Created by Михаил on 2019-04-05.
//

#include "Loader.h"
#include <fstream>
#include <iostream>
#include <json.hpp>

using json = nlohmann::json;

std::vector<Loader::Result> Loader::parseObjects(std::string JSONpath) {
    // Read json data from file
    std::fstream file(JSONpath, std::ios::in | std::ios::binary);
    if(file.is_open()) {

        json obj;
        file >> obj;
        // If objects exists update it's params.
        // If not - create a new one
        for(nlohmann::json::iterator it = obj.begin(); it < obj.end(); it++) {
            if(!(*it)["id"].is_null()) {
                __updateExistingObj(*it);
            } else {
                __createNewObj(*it);
            }
        }
    }
    return loadedObjects;
}
bool Loader::__createNewObj(const nlohmann::json& objDesc) {
    // Validate if object prototype exists
    if(!objectTypes[objDesc["name"]]) {
        return false;
    }
    // Create a new object and set it's params
    LoadableObjectBase* obj = objectTypes[objDesc["name"].get<std::string>()]();
    obj->setParams(objDesc);

    Result* result = new Result(objDesc["name"].get<std::string>(), obj);
    loadedObjects.push_back(*result);
    // Return true on success
    return true;
}
bool Loader::__updateExistingObj(const json& objDesc) {
    // Validate if object exists
    int id = objDesc["id"].get<int>();

    if(id < 0 || id >= loadedObjects.size()) {
        return false;
    }

    //Get object by id and update it's params
    loadedObjects[objDesc["id"].get<int>()].getObject()->setParams(objDesc);
    // Return true ob success
    return true;
}
void Loader::reset() {
    // Remove stored variables
    loadedObjects.clear();
    objectTypes.clear();
}