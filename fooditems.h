#include <string>
#include <map>
#include <vector>
#include "item.h"

#ifndef FOODITEMS_H
#define FOODITEMS_H
class fooditems
{

	public:
		fooditems();
		void addItem(std::string upc, const item& itm);
		item& getItem(std::string upc);
		std::string getName(std::string upc);
		std::map<std::string, item> & getItemList();

	private:
		std::map<std::string, item> *fimap;

};

#endif
