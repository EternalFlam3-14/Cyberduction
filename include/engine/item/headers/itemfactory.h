#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "item.h"

#include "mapfactory.h"

class ItemFactory_C
{
public:

    ItemFactory_C(std::map <std::string, std::string> TypeMap) : ItemTypeMap(TypeMap) {};

    std::shared_ptr<ItemStack_C> new_Item(int count, std::string itemname);

    std::string get_Type(std::string itemname);

private:

    std::map <std::string, std::string> ItemTypeMap;

};

#endif