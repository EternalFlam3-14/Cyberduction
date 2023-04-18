#include "slot.h"


bool Slot_C::increase_Stack(std::shared_ptr<ItemStack_C> &inStack)
{
    if (Stack)
    {
        Stack->increase_Stack(inStack);
        return 1;
    }
    Stack = std::move(inStack);
    return 1;
}