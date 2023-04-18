#ifndef STORAGE_H
#define STORAGE_H
#include <memory>
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/access.hpp>

class Storage
{
public:

// Json

    std::string Json(std::string &name);

    void SaveJson(std::string &name, auto data);

    void LoadJson(std::string &name, auto data);
    
// Bin

    std::string Bin(std::string &name);

    void SaveBin(std::string &name, auto data);

    void LoadBin(std::string &name, auto data);

private:

    std::string Binary = ".bin";

    std::string JSON = ".json";

};

#endif