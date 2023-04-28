#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

#include <map>
#include <memory>
#include <string>
#include <vector>
#include <Cereal.h>

class MapFactory_C
{
public:

    // Loads the Item/Type map
    // Returns true if load succeded, returns false if load failed
    bool load(std::string Filename);

    const std::map<std::string, std::string> Map() const { return TypeMap; };

    const std::string MainItemFile() const { return CyberItemFile; };

    const std::string AuxItemFile() const { return ForgeItemFile; };

private:

    // Returns the ItemNames and ItemTypes vectors from the database as a 2d vector of strings
    std::vector<std::vector<std::string>> load_Arrays(Cereal::Object* Items);

    void build_Map(Cereal::Object* TypeMapObject, std::vector<std::vector<std::string>> ItemArrays);

    // Internal check method used to verify the map isn't missing anything
    bool check_Error(std::map <std::string, std::string> ItemTypeMap, std::vector<std::vector<std::string>> ItemArrays);

    std::map <std::string, std::string> TypeMap;

    const std::string CyberItemFile = "Cyberduction/data/item.db";
    const std::string ForgeItemFile = "../data/item.db";
};
#endif