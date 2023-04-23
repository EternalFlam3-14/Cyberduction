#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

#include <map>
#include <string>
#include <vector>
#include <Cereal.h>

class MapFactory_C
{
public:

    MapFactory_C() {;};

    bool load();


private:

    // Returns the ItemNames and ItemTypes vectors from the database as a 2d vector of strings
    std::vector<std::vector<std::string>> load_Arrays(Cereal::Object* Items);

    // Returns the ItemName/ItemType map
    std::map <std::string, std::string> build_Map(Cereal::Object* TypeMap, std::vector<std::vector<std::string>> ItemArrays);

    // Internal check method used to verify the map isn't missing anything
    bool has_Error(std::map <std::string, std::string> ItemTypeMap, std::vector<std::vector<std::string>> ItemArrays);

    std::string Filename = "config/item.db";

    std::map <std::string, std::string> TypeMap;

};
#endif