#include "mapfactory.h"
#include <algorithm>

bool MapFactory_C::load()
{
    // Read file into buffer
    Cereal::Buffer buf(1024);
    buf.readFile(Filename);

    // Read buffer information into the database
    Cereal::Database* db = new Cereal::Database;
    db->read(buf);

    // Grab the Items object out of the database
    Cereal::Object* ItemsObject = db->getObject("Items");

    // Grab the TypeMap object from the database
    Cereal::Object* TypeMapObject = db->getObject("TypeMap");

    // Contains ItemNames and Types, [0] and [1] respectively
    auto ItemArrays = load_Arrays(ItemsObject);

    // The map is loaded in from the Cereal Object
    TypeMap = build_Map(TypeMapObject, ItemArrays);

    delete db; // Deletes all Cereal instances

    return has_Error(TypeMap, ItemArrays);
}

std::vector<std::vector<std::string>> MapFactory_C::load_Arrays(Cereal::Object* Items)
{
    // Gather arrays from object
    std::vector<Cereal::Array*> ItemArrays = Items->getArrays(); 
    
    // Seperate arrays into respective variables
    std::vector<std::vector<std::string>> ItemInfo;

    ItemInfo.push_back(ItemArrays[0]->getArray<std::string>());

    ItemInfo.push_back(ItemArrays[1]->getArray<std::string>());

    return ItemInfo;
}

std::map<std::string, std::string> MapFactory_C::build_Map(Cereal::Object *TypeMap, std::vector<std::vector<std::string>> ItemArrays)
{

    std::map <std::string, std::string> ItemTypeMap;

    for (auto Item : ItemArrays[0])
    {
        // Item's paired type
        std::string Type;
        
        // Fetch the string under the name of the current item
        Type = TypeMap->getField(Item)->getValue<std::string>();

        // Error if the paired type cannot be found in the Item Type array
        if (std::find(ItemArrays[1].begin(), ItemArrays[1].end(), Type) == ItemArrays[1].end())
        {
            continue;
        }

        // Store the pair into the map with the item as the key
        ItemTypeMap.emplace(std::pair<std::string, std::string> (Item, Type));
    }
    return ItemTypeMap;
}

bool MapFactory_C::has_Error(std::map <std::string, std::string> ItemTypeMap, std::vector<std::vector<std::string>> ItemArrays)
{
    std::vector<std::string> MissingItems, MissingTypes;

    // First check that all items exist in the Map
    for (auto Item : ItemArrays[0])
    {
        if(ItemTypeMap.find(Item) == ItemTypeMap.end())
        {
            MissingItems.push_back(Item);
        }
    }

    // Then, check that all types exist in the Map
    for (auto Type : ItemArrays[1])
    {
        if(ItemTypeMap.find(Type) == ItemTypeMap.end())
        {
            MissingTypes.push_back(Type);
        }
    }

    // If any missing elements occur, this function returns true
    if (MissingItems.size() || MissingTypes.size())
    {
        return true;
    }
    return false;
}
