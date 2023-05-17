#include "itemforge.h"
#include <mapfactory.h>
#include <utility.hpp>
#include <iostream>

bool file_Load()
{
    std::cout << "Welcome to the Item Forge!\nYou can edit item information for the Cyberduction program here!\nIs there a file to load? Note that input is not case-sensitive.\nYES / NO\n";
    std::string in; std::cin >> in;
    lowercase(in);

    return in == "yes";

}

std::string UserInput()
{
    std::string input; 
    std::cout << "What would you like to do?\nNEW / EDIT / VIEW / SAVE / EXIT\n";

    std::cin >> input;
    lowercase(input);

    return input;
}

void load(ItemForge_C &Forge)
{
    MapFactory_C Factory;

    Factory.load(Factory.AuxItemFile()) ? 
    ( Forge.set_Map(Factory.Map()), Forge.load_Arrays(), std::cout << "File loaded\n" ) :
    ( std::cout << "File loading failed\n" ) ;
}

void edit_Name(ItemForge_C &Forge, std::map<std::string, std::string>::iterator &pair)
{
    std::string input;
    bool edit_complete = false;
    while (!edit_complete)
    {
        std::cout << "What should the new name be?\n";
        std::string name; std::cin >> name;

        std::cout << name << ", correct? YES / NO / EXIT\n";
        std::cin >> input; lowercase(input);

        switch (hash(input))
        {
            case "exit"_:
            {
                edit_complete = true;
                break;
            } // case
            case "no"_:
            {
                break;
            } // case
            case "yes"_:
            {
                auto type = pair->second;

                std::pair<const std::string, std::string> newpair = std::pair<std::string, std::string> (name, type);

                Forge.erase_Element(name);
                Forge.add_Pair(newpair);

                edit_complete = true;
                break;
            } // case
            default:
            {
                std::cout << "Input failed. Try again.\n";
                break;
            } // case
        } // switch
    } // while(edit_complete) = false
} // edit_Name

void edit_Type(ItemForge_C &Forge, std::map<std::string, std::string>::iterator &pair)
{
    std::string input;
    bool edit_complete = false;
    while (!edit_complete)
    {
        std::cout << "What should the new type be?\n";
        std::string type; std::cin >> type;

        std::cout << type << ", correct? YES / NO / EXIT\n";
        std::cin >> input; lowercase(input);

        switch (hash(input))
        {
            case "exit"_:
            {
                edit_complete = true;
                break;
            } // case
            case "no"_:
            {
                break;
            } // case
            case "yes"_:
            {

                auto name = pair->first;

                std::pair<const std::string, std::string> newpair = std::pair<std::string, std::string> (name, type);

                Forge.erase_Element(name);
                Forge.add_Pair(newpair);

                edit_complete = true;
                break;
            } // case
            default:
            {
                std::cout << "Input failed. Try again.\n";
                break;
            } // case
        } // switch
    } // while(edit_complete) = false
} // edit_Type

void edit(ItemForge_C &Forge)
{
    bool exit = false;
    while (!exit)
    {
        std::cout << "What item do you wish to edit?\nEXIT / ITEM NAME\n";
        std::string input, in; std::cin >> input;

        if (in = input; lowercase(in), in == "exit")
        {
            std::cout << "Exiting\n";
            break;
        }

        auto pair = Forge.get_Element(input);
        if (pair == Forge.get_Map().end())
        {
            std::cout << "Key not found\n";
            continue;
        }
        
        std::cout << pair->first << ", " << pair->second << "\nWhat would you like to edit?\nNAME / TYPE / DELETE / EXIT\n";
        std::cin >> input;

        lowercase(input);
        switch (hash(input))
        {
            case "exit"_:
            {
                exit = true;
                break;
            } // case
            case "delete"_:
            {
                Forge.erase_Element(pair->first) ? std::cout << "Item erased\n" :
                std::cout << "Item delete failed\n";
                exit = true;
                break;
            }
            case "name"_:
            {
                edit_Name(Forge, pair);
                exit = true;
                break;
            } // case
            case "type"_:
            {
                edit_Type(Forge, pair);
                exit = true;
                break;
            } // case
            default:
            {
                std::cout << "Input failed. Try again.\n";
            } // case
        } // switch
    } // while(exit) = false
} // edit

int main()
{
    ItemForge_C Forge;
    bool end = false;

    if (file_Load())
    {
        load(Forge);
    }
    while (!end)
    {
        switch (hash(UserInput()))
        {
            case "new"_:
            {
                std::string ItemName, ItemType;

                std::cout << "Enter the item's name\n";
                std::cin >> ItemName;

                std::cout << "Enter the item's type\n";
                std::cin >> ItemType;

                std::pair<std::string, std::string> newpair(ItemName, ItemType);
                Forge.add_Pair(newpair);

                std::cout << ItemName << " " << Forge.get_Map().at(ItemName) << '\n';
                break;
            } // case
            case "edit"_:
            {
                edit(Forge);
                break;
            } // case
            case "view"_:
            {
                for (auto element : Forge.get_Map())
                {
                    std::cout << element.first << ' ' << element.second << '\n';
                }
                break;
            } // case
            case "save"_:
            {
                if (!Forge.save_Map())
                {
                    std::cout << "Map saving failed\n";
                    break;
                }
                std::cout << "Map saved successfully\n";
                break;
            } // case
            case "exit"_:
            {
                end = true;
                break;
            } // case
            default:
            {
                std::cout << "Input failed. Try again.\n";
            } // case
        } // switch
    } // while(exit) = false
} // main