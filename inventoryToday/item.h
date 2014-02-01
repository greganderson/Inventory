#include <iostream>
#include <string>

using namespace std;

class items
{

friend class warehouse.h

 private:
  item();
  string upc ;
  int shelfLife;
  string name;


 public:
  item(string upc, int sl, string name);

};
