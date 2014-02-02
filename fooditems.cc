#include <string>
#include "fooditems.h"
#include <map>
#include <iterator>

using namespace std;

class item;
fooditems::fooditems()
{
	fimap = new std::map<string, item>;
}


void fooditems::addItem(string upc, const item& itm)
{

	//item item1 = new item(itm);
	(*fimap)[upc] = itm;

}

/** 
 * Provided a upc, the function will return the item 
 * corresposnding to that upc.
 */
item& fooditems::getItem(string upc)
{
	return (*fimap)[upc];
}


/*
 * Returns a list of items.
 */
vector<string> fooditems::InventoryList()
{
  vector<string> list;
  string fitem;
  for (map<string, item >::iterator it = fimap->begin(); it != fimap->end(); ++it) {
    fitem = it->first;
    list.push_back(fitem);
  }
  return list;
}

/*
 *
 */
std::string fooditems::getName(std::string upc)
{
   return (*fimap)[upc].getName(); 

 }
