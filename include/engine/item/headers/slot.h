#ifndef SLOT_H
#define SLOT_H

#include "item.h"

class Slot
{
public:

    Slot(const std::string &type) : Type(type) {};
    Slot(std::shared_ptr<ItemStack> &stack) : Stack(stack), Type(stack->get_Type()) {};

    // Return the Slot's type
    const std::string ItemType() const { return Type; };

    const int stack_Size() const { return Stack->stack_Size(); };

    const bool increase_Stack(std::shared_ptr<ItemStack> &inStack);

private:

    std::string Type;
    std::shared_ptr<ItemStack> Stack;

};
#endif