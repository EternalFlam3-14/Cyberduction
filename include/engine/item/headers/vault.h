#ifndef VAULT_H
#define VAULT_H

#include <string>
#include <unordered_map>
#include "slot.h"
#include "vector"

class Vault
{
public:

    void add_Slot(std::shared_ptr<Slot> &slot);

    const bool add_Item(std::shared_ptr<ItemStack> &inStack);

    // Returns a string of all the items in the vault
    const std::string print_AllSlots();

    // Returns a string containing the item in the specified slot
    const std::string print_Slot(int slotno);


private:

    std::vector<std::shared_ptr<Slot>> Slots;
    std::unordered_multimap<std::string, int> SlotTypeIndices;

};


#endif