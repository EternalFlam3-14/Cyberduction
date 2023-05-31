#ifndef ITEMFORGE_H
#define ITEMFORGE_H
#include <cereal.h>
#include <memory>
#include <unordered_map>
#include <string>

class ItemForge
{
public:

    // Internal map setter
    void set_Map(std::unordered_map<std::string, std::string> existingMap) { ItemTypeMap = existingMap; };

    // Returns the IDs and ItemTypes vectors from the database as a 2d vector of strings
    void load_Arrays();

    // Save the internal map to file
    bool save_Map();

    // Add element to map
    void add_Pair(std::pair<std::string, std::string> input) { ItemTypeMap.emplace(input); };

    // Getter
    const std::vector<std::string> IDs() const { return ItemVectors.at(0); };
    // Getter
    const std::vector<std::string> ItemTypes() const { return ItemVectors.at(1); };
    // Getter
    const std::unordered_map<std::string, std::string>& get_Map() const { return ItemTypeMap; };

    // Check if element exists in ItemTypeMap
    bool element_Exists(std::string key) { return (ItemTypeMap.find(key) != ItemTypeMap.end()) ? true : false; }

    // Returns get_Map().end() if key not found
    auto get_Element(std::string key) { return ItemTypeMap.find(key); };

    // Returns true if element is erased from ItemTypeMap
    auto erase_Element(std::string key) { return element_Exists(key) ? (ItemTypeMap.erase(key), true) : false; }

private:

    // IDs as the first vector, ItemTypes as the second vector, expandable as needed
    std::vector<std::vector<std::string>> ItemVectors;

    // ID and ItemType pairing
    std::unordered_map<std::string, std::string> ItemTypeMap;

    // Static path to the file
    const std::string ItemFile = "../data/item.db";

};
#endif