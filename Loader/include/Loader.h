//
// Created by Михаил on 2019-04-05.
//

#include <map>
#include <json.hpp>
#include <Filter.h>
#include <LoadableObjectBase.h>
using nlohmann::json;
namespace mbtsky {
    class Loader {
        //*********************************************************************
        // private constructor for preventing creation of new copies
        //*********************************************************************
        Loader() = default;

        //*********************************************************************
        // Class for storing loaded objects and names
        //*********************************************************************
        class Result {
            //*****************************************************************
            // type name inherited from LoadableObjectBase
            //*****************************************************************
            std::string objTypeName;

            //*****************************************************************
            // pointer to object
            //*****************************************************************
            LoadableObjectBase *obj;

            //*****************************************************************
            //  Never used
            //*****************************************************************
            Result() = default;

        public:

            //*****************************************************************
            // @param name - objTypeName
            // @param obj_ - LoadableObjectBase ancestor
            //*****************************************************************
            Result(const std::string &name, LoadableObjectBase *obj_) {
                obj = obj_;
                objTypeName = name;
            }

            //*****************************************************************
            // getObjectTypeName
            // @result object type name
            //*****************************************************************
            std::string getObjectTypeName() { return objTypeName; }

            //*****************************************************************
            //@result pointer to object
            //*****************************************************************
            LoadableObjectBase *getObject() { return obj; }

        };

        //*********************************************************************
        // For storing constructors
        //*********************************************************************
        std::map<std::string, LoadableObjectBase *(*)()> objectTypes;

        //*********************************************************************
        // ResultList
        //*********************************************************************
        std::vector<Result> loadedObjects;

        //*********************************************************************
        // __updateExistingObject
        // if objects exists update it by object's id
        //*********************************************************************
        bool __updateExistingObj(const json &objDesc);

        //*********************************************************************
        // __createNewObj
        // create object by type name
        //*********************************************************************
        bool __createNewObj(const json &objDesc);

    public:

        //*********************************************************************
        // Singleton structure
        //*********************************************************************
        static Loader *instance() {
            static Loader *INSTANCE = new Loader();
            return INSTANCE;
        };

        //*********************************************************************
        // setObjectTypeNames
        // must be set before loading objects
        //*********************************************************************
        void setObjectTypes(const std::map<std::string,
                LoadableObjectBase *(*)()> &objectTypes_) {
            // Set object types that can be loaded
            objectTypes = objectTypes_;
        }

        //*********************************************************************
        // reset
        // remove all stored data
        //*********************************************************************
        void reset();

        //*********************************************************************
        // parseObjects
        // Load objects from json file by it's path
        //*********************************************************************
        std::vector<Result> parseObjects(std::string);
    };
}