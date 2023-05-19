#include "mapfactory.h"
#include <algorithm>
#include <unordered_set>
#include <iostream>
#include <ranges>

const bool MapFactory_C::load(const std::string &Filename)
{
    // Read file into buffer
    Cereal::Buffer buf(1024);
    if (!buf.readFile(Filename))
    {
        return false;
    }

    // Read buffer information into the database
    Cereal::Database* db = new Cereal::Database;
    db->read(buf);

    // Grab the Items object out of the database
    Cereal::Object* ItemsObject = db->getObject("Items");
    if (ItemsObject == nullptr)
    {
        return false;
    }
    // Grab the TypeMap object from the database
    Cereal::Object* TypeMapObject = db->getObject("TypeMap");
    if (TypeMapObject == nullptr)
    {
        return false;
    }
    // Contains ItemNames and Types, [0] and [1] respectively
    auto ItemArrays = load_Arrays(ItemsObject);

    // The map is loaded in from the Cereal Object
    build_Map(TypeMapObject, ItemArrays);

    return check_Error(TypeMap, ItemArrays);
}

std::vector<std::vector<std::string>> MapFactory_C::load_Arrays(Cereal::Object* Items)
{
    std::vector<Cereal::Array*> ItemArrays = Items->getArrays(); 
    
    std::vector<std::vector<std::string>> ItemInfo;

    // Set ItemInfo size to whichever array is larger
    ItemInfo.reserve(std::max(ItemArrays[0]->getSize(), ItemArrays[1]->getSize()));
    
    // ItemNames
    ItemInfo.push_back(ItemArrays[0]->getArray<std::string>());

    // ItemTypes
    ItemInfo.push_back(ItemArrays[1]->getArray<std::string>());

    return ItemInfo;
}

void MapFactory_C::build_Map(Cereal::Object *TypeMapObject, std::vector<std::vector<std::string>> ItemArrays)
{
    std::unordered_set<std::string> itemTypes;

    for (const auto& type : ItemArrays[1])
    {
        itemTypes.insert(type);
    }

    std::unordered_map <std::string, std::string> ItemTypeMap;

    for (const auto& item : ItemArrays[0])
    {
        // Fetch the string under the name of the current item
        std::string type = TypeMapObject->getField(item)->getValue<std::string>();

        // Check if the paired type cannot be found in the item type set
        if (itemTypes.find(type) == itemTypes.end())
        {
            continue;
        }

        // Store the pair into the map with the item as the key and type as the value
        ItemTypeMap.emplace(std::pair<std::string, std::string> (item, type));
    }
    TypeMap = std::move(ItemTypeMap);
}

const bool MapFactory_C::check_Error(const std::unordered_map <std::string, std::string> &ItemTypeMap, const std::vector<std::vector<std::string>> &ItemArrays)
{
    // Declare variables & reserve size for performance
    std::vector<std::string> MissingItems, MissingTypes;
    MissingItems.reserve(ItemArrays[0].size());
    MissingTypes.reserve(ItemArrays[1].size());

    // Check that all items exist in the Map
    for (const auto& item : ItemArrays[0])
    {
        if (ItemTypeMap.count(item) == 0)
        {
            MissingItems.push_back(item);
        }
    }
    for (const auto& missing : MissingItems)
    {
        std::cout << missing << std::endl;
    }

    // Gather all types
    const auto& itemTypes = std::views::values(ItemTypeMap);

    // Check that all types exist in the Map
    for (const auto& type : ItemArrays[1])
    {
        if (std::find(itemTypes.begin(), itemTypes.end(), type) == itemTypes.end())
        {
            MissingTypes.push_back(type);
        }
    }
    for (const auto& missing : MissingTypes)
    {
        std::cout << missing << std::endl;
    }

    // If any missing elements occur, this function returns false
    return MissingItems.empty() && MissingTypes.empty();
}
