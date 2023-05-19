#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H


#include <map>
#include <string>

#include "item.h"

class ItemFactory_C
{
public:

    ItemFactory_C(const std::map<std::string, std::string>& TypeMap) : ItemTypeMap(TypeMap) {};

    std::shared_ptr<ItemStack_C> new_Item(int count, const std::string &itemname);

private:

    std::map<std::string, std::string> ItemTypeMap;

};

#endif