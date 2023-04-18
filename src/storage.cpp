#include "storage.h"
#include <iostream>
#include <string>
#include <fstream>

// Binary

std::string Storage::Bin(std::string &name)
{
	return name.append(Binary);
}

void Storage::LoadBin(std::string &name, auto data)
{
  	std::string filename = Bin(name);
	std::fstream Filein;
	Filein.open(filename, std::fstream::in);
	if (!Filein.is_open())
	{
		std::cout << "File input opening failed";
		return;
	}
	else{
		cereal::BinaryInputArchive arin(Filein);
	
		arin(data);
	}

	Filein.close();
}

void Storage::SaveBin(std::string &name, auto data)
{
  	std::string filename = Bin(name);
	std::fstream Fileout;
	Fileout.open(filename, std::fstream::out);
	if (!Fileout.is_open())
	{
		std::cout << "File output opening failed";
		return;
	}
	else{
		cereal::BinaryOutputArchive arout(Fileout);

		arout(data);
	}

	Fileout.close();

}

// Json

std::string Storage::Json(std::string &name)
{
	return name.append(JSON);
}

void Storage::LoadJson(std::string &name, auto data)
{
  	std::string filename = Json(name);
    std::fstream Filein;
    Filein.open(filename, std::fstream::in);
    if (!Filein.is_open())
    {
    	std::cout << "File input opening failed";
    	return;
    }
    else{
    	cereal::BinaryInputArchive arin(Filein);

		arin(data);
    }

    Filein.close();
}

void Storage::SaveJson(std::string &name, auto data)
    {
  	std::string filename = Json(name);
	std::fstream Fileout;
	Fileout.open(filename, std::fstream::out);
	if (!Fileout.is_open())
	{
		std::cout << "File output opening failed";
		return;
	}
	else{
		cereal::JSONOutputArchive arout(Fileout);

		arout(data);
	}

	Fileout.close();

}
