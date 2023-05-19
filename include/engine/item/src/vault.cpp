#include "vault.h"
#include <iostream>

void Vault_C::add_Slot(std::shared_ptr<Slot_C> &slot)
{
    Slots.push_back(std::move(slot));

    // Update the SlotTypeIndices map with the new slot's type and index
    SlotTypeIndices[Slots.back()->ItemType()] = Slots.size() - 1;
}

const bool Vault_C::add_Item(std::shared_ptr<ItemStack_C> &inStack)
{
    std::string type(inStack->get_Type());

    // Search the lookup table for an entry
    auto it = SlotTypeIndices.find(type);
    if (it == SlotTypeIndices.end())
    {
        return false;
    }

    // Grab the slot position
    int slotno = it->second;

    Slots[slotno]->increase_Stack(inStack);
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



