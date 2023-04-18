#ifndef ITEM_H
#define ITEM_H

#include <string>

#include <cereal/access.hpp>
#include <cereal/types/string.hpp>


#include "itemenum.h"


class ItemStack_C
{
    friend class cereal::access;
public:
    ItemStack_C() : Count(0) {};
    ItemStack_C(std::string item, int count) : Item(item), Count(count) { set_Type(); };
    ItemStack_C(std::string item, std::string type, int count) : Item(item), Count(count), Type(type) {};

    void increase_Stack(std::shared_ptr<ItemStack_C> &inStack);

    void decrease_Stack(int count);

    int stack_Size() const { return Count; };

    std::string get_Type() const { return Type; };

private:
    int Count;
    std::string Item;
    std::string Type;

    void set_Type();

    template <class Archive>
    void serialize( Archive & archive )
    {
        archive( Count, Item, Type );
    };

};


#endif