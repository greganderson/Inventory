#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <vector>

#include "warehouses.h"


using namespace std;

/*
 * Creates a list of warehouses.
 */
warehouses::warehouses(fooditems & f, date & startDate) {
	*items = f;
	*start = startDate;
	whs = new map<string, warehouse*>;
}

/*
 * Destructs the list of warehouses.
 */
warehouses::~warehouses() {
	// TODO: Implement
}

/*
 * Takes a name of a warehouse and adds it to the list of warehouses.
 */
void warehouses::addWarehouse(string name) {
	(*whs)[name] = new warehouse(name, *items, *start);
}

/*
 * Returns the warehouse asked for.
 */
warehouse & warehouses::getWarehouse(string name) {
	return *(*whs)[name];
}

/*
 * Checks to see if any items are out of stock in all warehouses.
 */
void warehouses::unstockedProducts() {
	//For every item check in every warehouse's items list to see if it 
	//exists.

	map<string, string> listOfUnstocked;	// List of unstockeditems, mapping like (upc => name)


	map<string, item> itemList = items->getItemList();

	for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it) {
		//it-> first => warehouse.

		//List of the item that the warehouse contains.
		//myvector = (it->first).InventoryList();

		for (map<string, item>::iterator element = itemList.begin(); element != itemList.end(); ++element)
		{
			//If the item is found go to
			// the next warehouse.
			if(it->second->inStock(element->first))
				continue;
			else
				listOfUnstocked[element->first] = items->getName(element->first);
		}
	  
	}
}

/*
 * Checks to see which items are fully stocked (meaning stocked in every warehouse)
 */
void warehouses::fullystockedProducts() {
	map<string, string> listOfFullyStocked;	// List of fully stocked items, mapping like (upc => name)

	//For check through each item and once a warehouse says that it is not in stock that item
	// will not be added to the list. If it goes through every warehouse and they all have it
	// then when it reaches the end it will add it to the list.

	bool stocked;
	// Loop through each item in the fooditems
	map<string, item> itemList = items->getItemList();
	for (std::map<string, item>::iterator element = itemList.begin(); element != itemList.end(); ++element) {
		stocked = true;

		// Loop through each warehouse
		for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it) {
			if (!(it->second->inStock(element->first))) {
				stocked = false;
				break;
			}
		}
		
		// Check if it was in stock everywhere
		if (stocked)
			listOfFullyStocked[element->first] = items->getName(element->first);
	}

	for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it) {
		//it-> first => warehouse.

		//List of the item that the warehouse contains.
		//myvector = (it->first).InventoryList();
		map<string, item> itemList = items->getItemList();

		for (std::map<string, item>::iterator element = itemList.begin(); element != itemList.end(); ++element) {
			//If the item is found go to
			// the next warehouse.
			if(it->second->inStock(element->first))
				continue;
			else
				listOfFullyStocked[element->first] = items->getName(element->first);
		}
	  
	}
}
