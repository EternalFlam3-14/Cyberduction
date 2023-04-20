#ifndef MAP_FACTORY_H
#define MAP_FACTORY_H

#include <map>
#include <string>

class MapFactory_C
{
public:

    MapFactory_C() {;};

    std::map <std::string, std::string> load_Map();



private:

    std::string Filename = "config/item.db";


};
#endif