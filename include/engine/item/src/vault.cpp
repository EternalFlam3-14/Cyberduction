#include "vault.h"
#include <iostream>

void Vault_C::add_Slot(std::shared_ptr<Slot_C> &slot)
{
    Slots.push_back(std::move(slot));

    // Update the SlotTypeIndices map with the new slot's type and index
    SlotTypeIndices.emplace(Slots.back()->ItemType(), Slots.size() - 1);
}

const bool Vault_C::add_Item(std::shared_ptr<ItemStack_C> &inStack)
{
    std::string type(inStack->get_Type());

    // Count to see if ranges is needed
    int count = SlotTypeIndices.count(type);

    if (count == 0)
    {
        return false;
    }
    else if (count == 1)
    {
        // Grab entry from lookup table
        auto it = SlotTypeIndices.find(type);

        // Grab the slot position
        int slotno = it->second;

        if (!Slots[slotno]->increase_Stack(inStack))
        {
            return false;
        }
    }
    else if (count > 1)
    {
        // Gather slots, iterate over and attempt to increase stack
        auto ranges = SlotTypeIndices.equal_range(type);

        int fails = 0;

        for (auto it = ranges.first; it != ranges.second; ++it)
        {
            if (!Slots[it->second]->increase_Stack(inStack))
            {
                ++fails;
                continue;
            }
            break;
        }
        if (fails == count)
        {
            return false;
        }
    }
    return true;
}

const std::string Vault_C::print_AllSlots()
{
    std::string output;
    for (int i(0); i < Slots.size(); i++)
    {
        output.append(print_Slot(i));

        // Only add a newline if there are more elements
        if ((i+1) != Slots.size()) 
        {
            output.append("\n");
        }
    }
    return output;
}


const std::string Vault_C::print_Slot(int slotno)
{
    if (Slots[slotno]->ItemType().empty()) // If the type's string is ""
    {
        return "empty type";
    }
    if (!Slots[slotno]->stack_Size()) // If stack is empty
    {
        return "empty slot";
    }

    return Slots[slotno]->ItemType() + " " + std::to_string(Slots[slotno]->stack_Size());
}



