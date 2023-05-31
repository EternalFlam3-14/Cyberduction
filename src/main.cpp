#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vault.h>
#include <mapfactory.h>
#include <itemfactory.h>

void generalTest()
{
    srand (time(NULL));

    MapFactory MapFactory;

    if (!MapFactory.load(MapFactory.MainItemFile()))
    {
        std::cout << "Item loading failed";
        return;
    }

    ItemFactory ItemFactory(MapFactory.Map());
    
    Vault Vault;

    auto itemname = "iron_ore";
    auto item = ItemFactory.new_Item(10, itemname);
    auto slot = std::make_shared<Slot> (item);
    
    Vault.add_Slot(slot);

    std::cout << Vault.print_AllSlots() << std::endl;

    auto newItem = ItemFactory.new_Item(410, itemname);

    Vault.add_Item(newItem);

    auto aluminum_item = "bauxite_ore";

    item = ItemFactory.new_Item(rand() % 100 + 1, aluminum_item);

    auto newSlot = std::make_shared<Slot> (item);

    Vault.add_Slot(newSlot);

    std::cout << Vault.print_AllSlots() << std::endl;
}

int main()
{
    generalTest();
}