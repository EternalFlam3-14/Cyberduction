#include <iostream>
#include "game.h"

void generalTest()
{
    Vault_C Vault;

    Vault.add_Slot(std::make_shared<Slot_C> (ItemStack_C("iron_ingot", 10)));

    Vault.add_Slot(std::make_shared<Slot_C> ("processed_crop"));

    ItemStack_C item("flour", 69);

    std::shared_ptr<ItemStack_C> Stack = std::make_shared<ItemStack_C>(item);

    if (Vault.add_Item(Stack))
    {
        std::cout << Vault.print_AllSlots() << std::endl;
    }
    else{
        std::cout << "rejected" << std::endl;
    }

}

int main()
{
    generalTest();
}