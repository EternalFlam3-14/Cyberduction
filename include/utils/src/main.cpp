#include "itemforge.h"
#include <mapfactory.h>
#include <utility.hpp>
#include <iostream>

bool greeting()
{
    std::cout << "Welcome to the Item Forge!\nYou can edit item information for the Cyberduction program here!\nIs there a file to load?\nY / N" << std::endl;
    char in;
    std::cin >> in;
    in = tolower(in);
    switch (in)
    {
        case 'y':
        {
            return true;
            break;
        }
        default:
        {
            return false;
            break;
        }
    }

}

std::string UserInput()
{
    std::string input; 
    std::cout << "What would you like to do?\nNEW / EDIT / VIEW / SAVE / CLOSE" << std::endl;

    std::cin >> input;
    lowercase(input);

    return input;
}

void load(ItemForge_C& Forge)
{
    MapFactory_C Factory;
    switch (Factory.load(Factory.AuxItemFile()))
    {
        case true:
        {
            Forge.set_Map(Factory.Map());
            Forge.load_Arrays();
            std::cout << "File loaded\n";
            break;
        }
        default:
        {
            std::cout << "File loading failed\n";
            break;
        }
    }
}

main()
{
    ItemForge_C Forge;
    bool end = false;

    if (greeting())
    {
        load(Forge);
    }
    while (!end)
    {
        switch (hash(UserInput()))
        {
            case "new"_:
            {
                std::string ItemName;
                std::string ItemType;

                std::cout << "Enter new item\n";
                std::cin >> ItemName;

                std::cout << "Enter the item's type\n";
                std::cin >> ItemType;

                std::pair<std::string, std::string> newpair(ItemName, ItemType);
                Forge.add_Pair(newpair);

                std::cout << ItemName << " " << Forge.get_Map().at(ItemName) << '\n';
                break;
            }
            case "edit"_:
            {
                std::cout << "Not built yet" << std::endl;
                break;
            }
            case "view"_:
            {
                for (auto element : Forge.get_Map())
                {
                    std::cout << element.first << ' ' << element.second << '\n';
                }
                break;
            }
            case "save"_:
            {
                Forge.save_Map();
                break;
            }
            case "close"_:
            {
                end = true;
                break;
            }
            default:
            {
                std::cout << "Input failed. Try again." << std::endl;
            }
        }
    }
}