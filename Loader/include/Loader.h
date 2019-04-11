//
// Created by Михаил on 2019-04-05.
//

#include <map>
#include <json.hpp>
#include <Filter.h>
#include <LoadableObjectBase.h>
using nlohmann::json;
class Loader {
    // private constructor for preventing creation of new copies
    Loader() = default;
    // Class for storing loaded objects and names
    class Result {
        std::string objTypeName;
        LoadableObjectBase* obj;
    public:
        Result() = default;
        Result(const std::string& name, LoadableObjectBase* obj_) {
            obj = obj_;
            objTypeName = name;
        }
        std::string getObjectTypeName() {
            return objTypeName;
        }
        LoadableObjectBase* getObject() {
            return obj;
        }
    };
    // For storing constructors
    std::map<std::string, LoadableObjectBase*(*)()> objectTypes;
    // ResultList
    std::vector<Result> loadedObjects;
    bool __updateExistingObj(const json& objDesc);
    bool __createNewObj(const json& objDesc);
    // initialize Loader
public:
    // Singleton structure
    static Loader* instance() {
        static Loader* INSTANCE = new Loader();
        return INSTANCE;
    };
    void setObjectTypes(const std::map<std::string,
            LoadableObjectBase*(*)()> &objectTypes_) {
        // Set object types that can be loaded
        objectTypes = objectTypes_;
    }
    void reset();
    // Load objects from json file by it's path
    std::vector<Result> parseObjects(std::string);
    // Default constructor
};