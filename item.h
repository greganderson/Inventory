#include <iostream>
#include <string>

class item
{
 private:
  std::string upc;
  int shelfLife;
  std::string name;

 public:
  item();
  item(std::string upc, int shelflife, std::string name);
  item(const item & other);
  std::string getUpc();
  int getShelfLife();
  std::string getName();

};
