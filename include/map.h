#ifndef MAP_H
#define MAP_H
#include <map>
#include <memory>
//#include "itemenum.h"
#include <cereal/types/map.hpp>

namespace Map_N
{
    bool loadMap();

    bool saveMap();

    std::string Map(std::string inItem);

    extern std::map<std::string, std::string> itemMap;

    template <class Archive>
    void serialize( Archive & archive )
    {
        archive( itemMap );
    };

};

#endif