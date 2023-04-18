#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <map>
#include <string>

#include "item.h"

class ItemFactory_C
{
public:

    ItemFactory_C(std::map <std::string, std::string> itemmap) : ItemMap(itemmap) {};

    std::shared_ptr<ItemStack_C> new_Item(int count, std::string itemname);

    std::string get_Type(std::string itemname);

private:

    std::map <std::string, std::string> ItemMap;

};

#endif