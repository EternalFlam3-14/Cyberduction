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

    // Loads the Item/Type map
    // Returns true if load succeded, returns false if load failed
    bool load();

    const std::map<std::string, std::string> Map() const { return TypeMap; };

private:

    // Returns the ItemNames and ItemTypes vectors from the database as a 2d vector of strings
    std::vector<std::vector<std::string>> load_Arrays(Cereal::Object* Items);

    // Returns the ItemName/ItemType map
    std::map <std::string, std::string> build_Map(Cereal::Object* TypeMap, std::vector<std::vector<std::string>> ItemArrays);

    // Internal check method used to verify the map isn't missing anything
    bool check_Error(std::map <std::string, std::string> ItemTypeMap, std::vector<std::vector<std::string>> ItemArrays);

    std::string Filename = "config/item.db";

    std::map <std::string, std::string> TypeMap;

};
#endif