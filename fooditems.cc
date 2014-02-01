#include <isostream>
#include <string>


fooditem::fooditem()
{
  
  map<string, *item> *fimap = new map<string, *item>;

}

fooditem::~fooditem()
{
  delete *fimap;
}

fooditem::addItem(string upc, item itm)
{
  
  *fimap[upc] = itm;

}

fooditem::
