#ifndef SLOT_H
#define SLOT_H

#include "item.h"

class Slot_C
{
public:

    Slot_C(std::string type) : Type(type) {};
    Slot_C(std::shared_ptr<ItemStack_C> &stack) : Stack(stack), Type(stack->get_Type()) {};

    // Return the Slot's type
    const std::string ItemType() const { return Type; };

    const int stack_Size() const { return Stack->stack_Size(); };

    const bool increase_Stack(std::shared_ptr<ItemStack_C> &inStack);

private:

    std::string Type;
    std::shared_ptr<ItemStack_C> Stack;

};
#endif