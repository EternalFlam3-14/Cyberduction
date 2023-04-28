#ifndef ITEMFORGE_H
#define ITEMFORGE_H
#include <cereal.h>
#include <memory>
#include <map>
#include <string>

class ItemForge_C
{
public:

    ItemForge_C() {};

    // Internal map setter
    void set_Map(std::map<std::string, std::string> existingMap) { ItemTypeMap = existingMap; };

    // Returns the ItemNames and ItemTypes vectors from the database as a 2d vector of strings
    void load_Arrays();

    // Save the internal map to file
    void save_Map();

    // Add element to map
    void add_Pair(std::pair<std::string, std::string> input) { ItemTypeMap.emplace(input); };

    // Getter
    const std::vector<std::string> ItemNames() const { return ItemVectors.at(0); };
    // Getter
    const std::vector<std::string> ItemTypes() const { return ItemVectors.at(1); };
    // Getter
    const std::map<std::string, std::string> get_Map() const { return ItemTypeMap; };

private:

    std::vector<std::vector<std::string>> ItemVectors;

    std::map<std::string, std::string> ItemTypeMap;

    const std::string ItemFile = "../data/item.db";

};
#endif