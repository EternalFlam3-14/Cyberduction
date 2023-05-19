#include <iostream>
#include <vault.h>
#include <mapfactory.h>
#include <itemfactory.h>

void generalTest()
{
    MapFactory_C MapFactory;

    if (!MapFactory.load(MapFactory.MainItemFile()))
    {
        std::cout << "Item loading failed";
        return;
    }

    ItemFactory_C ItemFactory_C(MapFactory.Map());
    
    Vault_C Vault;

    auto itemname = "iron_ore";
    auto item = ItemFactory_C.new_Item(10, itemname);
    auto slot = std::make_shared<Slot_C> (item);
    
    Vault.add_Slot(slot);

    std::cout << Vault.print_AllSlots() << std::endl;


}

int main()
{
    generalTest();
}