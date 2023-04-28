#include "itemforge.h"
#include <ranges>
#include <iostream>

void ItemForge_C::load_Arrays()
{
    // Read map keys
    std::vector<std::string> ItemNames(std::views::keys(ItemTypeMap).begin(), std::views::keys(ItemTypeMap).end());
    // Read map values
    std::vector<std::string> ItemValues(std::views::values(ItemTypeMap).begin(), std::views::values(ItemTypeMap).end());
    ItemVectors.push_back(ItemNames);
    ItemVectors.push_back(ItemValues);
}

void ItemForge_C::save_Map()
{
    auto NameV = std::views::keys(ItemTypeMap);
    auto TypeV = std::views::values(ItemTypeMap);

    std::vector<std::string> ItemNames{ NameV.begin(), NameV.end() },
    /*    Keys & Values    */ItemTypes{ TypeV.begin(), TypeV.end() };

    // Build object to store map
    Cereal::Object* MapObject = new Cereal::Object("TypeMap");

    // Build object to store values
    Cereal::Object* ItemObject = new Cereal::Object("Items");

    for (int i=0; i < ItemNames.size(); i++)
    {
        Cereal::Field* Newfield = new Cereal::Field(ItemNames[i], ItemTypes[i]);
        MapObject->addField(Newfield);
    }

    ItemObject->addArray(new Cereal::Array("Names", ItemNames.data(), ItemNames.size()));
    ItemObject->addArray(new Cereal::Array("Types", ItemTypes.data(), ItemTypes.size()));

    Cereal::Buffer buf(1024);
    Cereal::Database* db = new Cereal::Database("ItemDB");

    db->addObject(MapObject);
    db->addObject(ItemObject);
    if (!db->write(buf))
    {
        std::cout << "Database failed to write to buffer" << std::endl;
        delete db;
        return;
    }
    if (!buf.writeFile(ItemFile))
    {
        std::cout << "Buffer failed to write to file" << std::endl;
        delete db;
        return;
    }
    delete db;
}
