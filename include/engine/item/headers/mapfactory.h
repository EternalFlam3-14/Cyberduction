#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

#include <unordered_map>
#include <memory>
#include <string>
#include <vector>
#include <Cereal.h>

class MapFactory_C
{
public:

    // Loads the Item/Type map
    // Returns true if load succeded, returns false if load failed
    const bool load(const std::string &Filename);

    // Getter
    const std::unordered_map<std::string, std::string> &Map() const { return TypeMap; };

    // File path for main program
    const std::string &MainItemFile() const { return CyberItemFile; };

    // File path for tools
    const std::string &AuxItemFile() const { return ForgeItemFile; };

private:

    // Returns the IDs and ItemTypes vectors from the database as a 2d vector of strings
    std::vector<std::vector<std::string>> load_Arrays(Cereal::Object* Items);

    // Self explainatory
    void build_Map(Cereal::Object* TypeMapObject, std::vector<std::vector<std::string>> ItemArrays);

    // Internal check method used to verify the map isn't missing anything
    const bool check_Error(const std::unordered_map <std::string, std::string> &ItemTypeMap, const std::vector<std::vector<std::string>> &ItemArrays);

    std::unordered_map <std::string, std::string> TypeMap;

    const std::string CyberItemFile = "data/item.db";
    const std::string ForgeItemFile = "../data/item.db";

};
#endif