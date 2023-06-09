#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>


class ItemStack
{
public:

    ItemStack() : Count(0) {};
    ItemStack(const std::string &itemID, const std::string &itemtype, const int &count) : ID(itemID), Count(count), Type(itemtype) {};

    void increase_Stack(std::shared_ptr<ItemStack> &inStack);

    void decrease_Stack(int count);

    const int stack_Size() const { return Count; };

    const std::string get_Type() const { return Type; };

private:

    int Count;
    std::string ID;
    std::string Type;

};


#endif