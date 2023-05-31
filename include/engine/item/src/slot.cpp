#include "slot.h"



const bool Slot::increase_Stack(std::shared_ptr<ItemStack> &inStack)
{
    if (Stack)
    {
        Stack->increase_Stack(inStack);
        return 1;
    }
    Stack = std::move(inStack);
    return 1;
}