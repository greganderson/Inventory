#include <string>
#include <map>
#include <queue>

#include "fooditems.h"
#include "item.h"

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class item;

class warehouse {


	private:
		std::map<std::string, std::queue<int>* > *inventory;	// Map of items, <UPC => Inventory>
		std::string name;
		fooditems *items;
		
	public:
		warehouse(std::string, fooditems &);
		void receive(std::string upc, int amount);
		void request(std::string upc, int amount);
		void clearInventory();
};
#endif
