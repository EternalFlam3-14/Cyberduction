#include "vault.h"
#include <iostream>

void Vault_C::add_Slot(std::shared_ptr<Slot_C> slot)
{
    Slots.push_back(slot);
}

bool Vault_C::add_Item(std::shared_ptr<ItemStack_C> &inStack)
{
    std::string type(inStack->get_Type());
    int slotno = check_Types(type);
    if (slotno == -1)
    {
        return 0;
    }
    std::cout << inStack->stack_Size() << std::endl;
    Slots[slotno]->increase_Stack(inStack);
    return 1;

}

int Vault_C::check_Types(std::string type)
{
    for (int i(0); i < Slots.size(); i++)
    {
        if (Slots[i]->ItemType() == type)
        {
            return i;
        }
    }
    return -1;
}

std::string Vault_C::print_AllSlots()
{
    std::string output;
    for (int i(0); i < Slots.size(); i++)
    {
        output.append(print_Slot(i));

        if ((i+1) != Slots.size()) // Only add a newline if there are more elements
        {
            output.append("\n");
        }
    }
    return output;
}


std::string Vault_C::print_Slot(int slotno)
{
    if (Slots[slotno]->ItemType().empty()) // Check Item Type
    {
        return "empty type";
    }
    if (!Slots[slotno]->stack_Size()) // Check Stack Size
    {
        return "empty slot";
    }

    return Slots[slotno]->ItemType() + " " + std::to_string(Slots[slotno]->stack_Size());

}



