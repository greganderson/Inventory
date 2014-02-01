#include <iostream>
#include <string>
#include <map>
#include "item.h"

class fooditems
{

 public:
  fooditems();
  void addItem(std::string upc, const item& itm);
  item& getItem(std::string upc);

 private:
  std::map<std::string, item> *fimap;

};

