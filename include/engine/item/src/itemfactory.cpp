#include <random>
#include <iostream>

#include "itemfactory.h"

std::shared_ptr<ItemStack_C> ItemFactory_C::new_Item(int count, const std::string &itemname)
{
    return std::make_shared<ItemStack_C> (itemname, ItemTypeMap[itemname], count);

}
