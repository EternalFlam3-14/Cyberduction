#include <random>
#include <iostream>

#include "itemfactory.h"

std::shared_ptr<ItemStack> ItemFactory::new_Item(int count, const std::string &itemID)
{
    return std::make_shared<ItemStack> (itemID, ItemTypeMap[itemID], count);

}
