#include "mapfactory.h"
#include <algorithm>
#include <iostream>
#include <ranges>

bool MapFactory_C::load(std::string Filename)
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
    // Gather arrays from object
    std::vector<Cereal::Array*> ItemArrays = Items->getArrays(); 
    
    // Seperate arrays into respective variables
    std::vector<std::vector<std::string>> ItemInfo;

    // ItemNames
    ItemInfo.push_back(ItemArrays[0]->getArray<std::string>());

    // ItemTypes
    ItemInfo.push_back(ItemArrays[1]->getArray<std::string>());

    return ItemInfo;
}

void MapFactory_C::build_Map(Cereal::Object *TypeMapObject, std::vector<std::vector<std::string>> ItemArrays)
{

    std::map <std::string, std::string> ItemTypeMap;

    for (auto Item : ItemArrays[0])
    {
        // Item's paired type
        std::string Type;
        
        // Fetch the string under the name of the current item
        Type = TypeMapObject->getField(Item)->getValue<std::string>();

        // Error if the paired type cannot be found in the Item Type array
        if (std::find(ItemArrays[1].begin(), ItemArrays[1].end(), Type) == ItemArrays[1].end())
        {
            continue;
        }

        // Store the pair into the map with the item as the key
        ItemTypeMap.emplace(std::pair<std::string, std::string> (Item, Type));
    }
    TypeMap = ItemTypeMap;
}

bool MapFactory_C::check_Error(std::map <std::string, std::string> ItemTypeMap, std::vector<std::vector<std::string>> ItemArrays)
{
    std::vector<std::string> MissingItems, MissingTypes;

    // First check that all items exist in the Map
    for (auto Item : ItemArrays[0])
    {
        if (ItemTypeMap.find(Item) == ItemTypeMap.end())
            {
                MissingItems.push_back(Item);
            }
    }
    for (auto missing : MissingItems)
    {
        std::cout << missing << std::endl;
    }


    std::vector<std::string> Types(std::views::values(ItemTypeMap).begin(),std::views::values(ItemTypeMap).end());
    // Then, check that all types exist in the Map
    for (auto Type : ItemArrays[1])
    {
        if(std::find(std::views::values(ItemTypeMap).begin(), std::views::values(ItemTypeMap).end(), Type) == std::views::values(ItemTypeMap).end())
        {
            MissingTypes.push_back(Type);
        }
    }
    for (auto missing : MissingTypes)
    {
        std::cout << missing << std::endl;
    }

    // If any missing elements occur, this function returns false
    if (MissingItems.size() || MissingTypes.size())
    {
        return false;
    }
    return true;
}
