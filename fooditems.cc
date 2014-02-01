#include <isostream>
#include <string>


fooditem::fooditem()
{
  
  map<string, item> *fimap = new map<string, item>;

}

fooditem::~fooditem()
{
  delete *fimap;
}

item fooditem::addItem(string upc, item itm)
{
  
  *fimap[upc] = itm;

}

/** 
 * Provided a upc, the function will return the item 
 * corresposnding to that upc.
 */
item fooditem::getItem(string upc)
{
  return (*fimap)[upc];
}
