#include <string>
#include "fooditems.h"
#include <map>

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
