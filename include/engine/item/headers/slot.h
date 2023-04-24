#ifndef SLOT_H
#define SLOT_H

#include "item.h"


class Slot_C
{
public:

    Slot_C() {;};
    Slot_C(std::string type) : Type(type) {};
    Slot_C(ItemStack_C stack) : Stack(std::make_shared<ItemStack_C> (stack)), Type(stack.get_Type()) {};

    // Return the Slot's type
    std::string ItemType() { return Type; };

    int stack_Size() const { return Stack->stack_Size(); };

    bool increase_Stack(std::shared_ptr<ItemStack_C> &inStack);

private:

    std::string Type;
    std::shared_ptr<ItemStack_C> Stack;

};
#endif