#include "item.h"

void ItemStack_C::set_Type()
{
	if (Item == "iron_ore" || Item == "bauxite_ore")
    {
        Type = "ore";
    }
    else if (Item == "aluminum_oxide")
    {
        Type = "processed_ore";
    }
    else if (Item == "iron_ingot" || Item == "aluminum_ingot")
    {
        Type = "metal";
    }
    else if (Item == "wheat" || Item == "rice")
    {
        Type = "raw_crop";
    }
    else if (Item == "flour" || Item == "rice_flour")
    {
        Type = "processed_crop";
    }
}

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

