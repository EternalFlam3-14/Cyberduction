#include "itemforge.h"
#include <ranges>
#include <iostream>

void ItemForge_C::load_Arrays()
{
    // Read map keys
    std::vector<std::string> IDs(std::views::keys(ItemTypeMap).begin(), std::views::keys(ItemTypeMap).end());
    // Read map values
    std::vector<std::string> ItemValues(std::views::values(ItemTypeMap).begin(), std::views::values(ItemTypeMap).end());

    ItemVectors.push_back(IDs);
    ItemVectors.push_back(ItemValues);
}

bool ItemForge_C::save_Map()
{
    // Gather map keys as IDs, values as Types
    std::vector<std::string> IDs{ std::views::keys(ItemTypeMap).begin(), std::views::keys(ItemTypeMap).end() },   ItemTypes{ std::views::values(ItemTypeMap).begin(), std::views::values(ItemTypeMap).end() };

    // Build object to store map, deleted with database (Cereal)
    Cereal::Object* MapObject = new Cereal::Object("TypeMap");

    // Build object to store values, deleted with database (Cereal)
    Cereal::Object* ItemObject = new Cereal::Object("Items");

    for (int i=0; i < IDs.size(); i++)
    {
        Cereal::Field* Newfield = new Cereal::Field(IDs[i], ItemTypes[i]);
        MapObject->addField(Newfield);
    }

    // Add the vectors to the item object
    ItemObject->addArray(new Cereal::Array("IDs", IDs.data(), IDs.size()));
    ItemObject->addArray(new Cereal::Array("Types", ItemTypes.data(), ItemTypes.size()));

    // Handlers
    Cereal::Buffer buf(1024);
    Cereal::Database* db = new Cereal::Database("ItemDB");

    // Add objects to database
    db->addObject(MapObject);
    db->addObject(ItemObject);

    // Write database to buffer
    if (!db->write(buf))
    {
        std::cout << "Database failed to write to buffer" << std::endl;
        delete db;
        return false;
    }
    // Write buffer to file
    if (!buf.writeFile(ItemFile))
    {
        std::cout << "Buffer failed to write to file" << std::endl;
        delete db;
        return false;
    }
    delete db;
    return true;
}
