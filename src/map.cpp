#include "map.h"
#include "storage.h"
#include <iostream>
#include <string>
#include <fstream>


// bool Map_N::loadMap()
// {
//   	std::string filename = "mods/map.bin";
// 	std::fstream Filein;
// 	Filein.open(filename, std::fstream::in);
// 	if (!Filein.is_open())
// 	{
// 		std::cout << "File input opening failed";
// 		return false;
// 	}
// 	else{
// 		cereal::BinaryInputArchive arin(Filein);
	
// 		arin(itemMap);
// 	}

// 	Filein.close();

// 	return true;

// }

// bool Map_N::saveMap()
// {
//   	std::string filename = "mods/map.bin";
// 	std::fstream Fileout;
// 	Fileout.open(filename, std::fstream::out);
// 	if (!Fileout.is_open())
// 	{
// 		std::cout << "File output opening failed";
// 		return false;
// 	}
// 	else{
// 		cereal::BinaryOutputArchive arout(Fileout);

// 		arout(itemMap);
// 	}

// 	Fileout.close();

// 	return true;
// }

// std::string Map_N::Map(std::string inItem)
// {
//     auto iter = itemMap.find(inItem);
// 	return iter->second;
// }

