#include <iostream>
#include <string>
#include <map>

class fooditems
{
  class item;

 public:
  fooditems();
  void addItem(std::string upc, item itm);
  item getItem(std::string upc);

 private:
  std::map<std::string, item> *fimap;

};

