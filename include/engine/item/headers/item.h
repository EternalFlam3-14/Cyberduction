#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>


class ItemStack_C
{
public:
    ItemStack_C() : Count(0) {};
    ItemStack_C(std::string item, std::string type, int count) : Item(item), Count(count), Type(type) {};

    void increase_Stack(std::shared_ptr<ItemStack_C> &inStack);

    void decrease_Stack(int count);

    int stack_Size() const { return Count; };

    std::string get_Type() const { return Type; };

private:
    int Count;
    std::string Item;
    std::string Type;

};


#endif