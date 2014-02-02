/*
 * Written by Greg Anderson and Jesus Zarate.
 */

#include <string>
#include "fooditems.h"
#include <map>
#include <iterator>

using namespace std;

class item;
fooditems::fooditems()
{
	fimap = new map<string, item>;
}


void fooditems::addItem(string upc, const item& itm)
{

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
 *
 */
string fooditems::getName(std::string upc)
{
   return (*fimap)[upc].getName(); 

 }

/*
 * Returns a pointer to the map of items.
 */
map<string, item> & fooditems::getItemList() {
	return *fimap;
}
