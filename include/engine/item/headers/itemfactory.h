#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H


#include <unordered_map>
#include <string>

#include "item.h"

class ItemFactory
{
public:

    ItemFactory(const std::unordered_map<std::string, std::string> &TypeMap) : ItemTypeMap(TypeMap) {};

    std::shared_ptr<ItemStack> new_Item(int count, const std::string &itemID);

private:

    std::unordered_map<std::string, std::string> ItemTypeMap;

};

#endif