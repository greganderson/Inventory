#include <iostream>
#include <string>

class fooditems
{
  friend class item.h;
 public:
  fooditems();
  void addItem(std::string upc, std::item itm)

 private:
    map<string, item> *fimap;

}

