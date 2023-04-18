#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include <cereal/types/base_class.hpp>
#include <cereal/types/memory.hpp>
#include <cereal/access.hpp>

using namespace std;
class Parent_C; // Forward declares
class Child;    // so my classes are in your order
class Family {

  friend class cereal::access;

public:
  Family() { ; }
  ~Family() { ; }

  vector<std::shared_ptr<Parent_C> > m_members;
private:
  template <class Archive>
  void serialize( Archive & ar )
  { ar( m_members ); }

};

class Parent_C {

  friend class cereal::access;

public:
  Parent_C() : m_name("") { ; }
  Parent_C(string name) : m_name(name) { ; }
  ~Parent_C() { ; }

  virtual string GetName() { return m_name; }
private:

  string m_name;

  template <class Archive>
  void serialize( Archive & ar )
  { ar( m_name ); }

};

class Child : public Parent_C {

  friend class cereal::access;

public:
  Child() : Parent_C(), m_age(0) { ; }
  Child(string name, int id) : Parent_C(name), m_age(id) { ; }
  ~Child() { ; }
  int m_age;
private:

  template <class Archive>
  void serialize( Archive & ar )
  { ar( cereal::base_class<Parent_C>( this ), m_age ); }

};
CEREAL_REGISTER_TYPE(Child)



void save_Bin(Family &Family)
{
  std::string filename = "data.bin";
  std::fstream Fileout;
  Fileout.open(filename, std::fstream::out);
  if (!Fileout.is_open())
  {
    std::cout << "File output opening failed";
    return;
  }
  else{
    cereal::BinaryOutputArchive arout(Fileout);

    arout(Family);
  }

  Fileout.close();
};

void save_Json(Family &Family)
{
  std::string filename = "data.json";
  std::fstream Fileout;
  Fileout.open(filename, std::fstream::out);
  if (!Fileout.is_open())
  {
    std::cout << "File output opening failed";
    return;
  }
  else{
    cereal::JSONOutputArchive arout(Fileout);

    arout(Family);
  }

  Fileout.close();
};

void load_Bin(Family &Family)
{
  std::string filename = "data.bin";
  std::fstream Filein;
  Filein.open(filename, std::fstream::in);
  if (!Filein.is_open())
  {
    return;
  }
  else{
    cereal::BinaryInputArchive arin(Filein);

    arin(Family);
  }

  Filein.close();
};

void load_Json(Family &Family)
{
  std::string filename = "data.json";
  std::fstream Filein;
  Filein.open(filename, std::fstream::in);
  if (!Filein.is_open())
  {
    return;
  }
  else{
    cereal::JSONInputArchive arin(Filein);

    arin(Family);
  }

  Filein.close();
};



int main() {

  // Create data
  auto timmy = std::make_shared<Child>("Timmy", 14);
  Family JohnsonFamily;
  JohnsonFamily.m_members.push_back(timmy);

  // Request file storage type
  std::string input;
  std::cout << "Use .Json format? (yes or no, defaults no)" << std::endl;
  std::cin >> input;

  // You can read JSON files
  bool JSON = false;
  if (input == "yes" || input == "Yes"){
    JSON = true;
  }

  // Asks if user wants to save data
  std::cout << "Save stored data? (yes or no, defaults yes)" << std::endl;
  std::cin >> input;

  // Save is default true
  bool save = true;
  if (input == "no" || input == "No"){
    save = false;
  }

  // Save data
  if (save){
    if (!JSON){
      save_Bin(JohnsonFamily);
    }
    else{
      save_Json(JohnsonFamily);
    }
  }
  
  // Data to load to
  Family FosterFamily;

  // Load data
  if (!JSON){
    load_Bin(FosterFamily);
  }
  else{
    load_Json(FosterFamily);
  }

  // Read data to terminal
  for (auto baseptr : FosterFamily.m_members)
  {
    auto child = dynamic_cast<Child*>(baseptr.get());
    if (child != nullptr) {
      cout << "Derived type inferred from serialized base pointer." << endl;
      cout << child->GetName() << " is " << child->m_age << endl;
    }
  }

  return 0;
}