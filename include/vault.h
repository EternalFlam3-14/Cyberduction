#ifndef VAULT_H
#define VAULT_H

#include <string>
#include "slot.h"
#include "vector"

class Vault_C
{
    friend class cereal::access;
public:

    void add_Slot(std::shared_ptr<Slot_C> slot);

    bool add_Item(std::shared_ptr<ItemStack_C> &inStack);

    // Returns position of slot with matching type. Returns -1 if no slot has a matching type
    int check_Types(std::string type);

    // Returns a string of all the items in the vault
    std::string print_AllSlots();

    // Returns a string containing the item in the specified slot
    std::string print_Slot(int slotno);


private:
    std::vector<std::shared_ptr<Slot_C>> Slots;

    template <class Archive>
    void serialize( Archive & archive )
    {
        archive( Slots );
    };

};


#endif