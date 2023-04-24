#include "item.h"


void ItemStack_C::increase_Stack(std::shared_ptr<ItemStack_C> &inStack)
{
    if (inStack->get_Type() == Type)
    {
        Count += inStack->stack_Size();
    }
    else if (!Type.size())
    {
        Count = inStack->stack_Size();
        Type = inStack->get_Type();
    }
}

void ItemStack_C::decrease_Stack(int count)
{

}

