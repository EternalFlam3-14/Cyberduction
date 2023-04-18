#ifndef MAPFACTORY_H
#define MAPFACTORY_H
#include <map>
#include <string>

class MapFactory_C
{
public:

    MapFactory_C() {};

    bool buildMap();

private:

    std::map<std::string, std::string> itemMap;

};


#endif