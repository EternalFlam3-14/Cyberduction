#include "item.h"


void ItemStack::increase_Stack(std::shared_ptr<ItemStack> &inStack)
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

void ItemStack::decrease_Stack(int count)
{

}

