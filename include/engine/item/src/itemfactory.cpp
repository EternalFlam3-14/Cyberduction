#include <random>
#include <iostream>

#include "itemfactory.h"

std::shared_ptr<ItemStack_C> ItemFactory_C::new_Item(int count, std::string itemname)
{
    return std::make_shared<ItemStack_C> (itemname, get_Type(itemname), count);

}

std::string ItemFactory_C::get_Type(std::string itemname)
{
    return ItemTypeMap[itemname];
}