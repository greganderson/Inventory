/*
 * Written by Greg Anderson and Jesus Zarate.
 */

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
map<string, string> & warehouses::printUnstockedProducts() {
	cout << "Unstocked Products:" << endl;

	// Get fooditem list
	map<string, item> itemList = items->getItemList();

	bool stocked;	// Keep track of whether an item is in stock somewhere

	// Loop through all items
	for (map<string, item>::iterator element = itemList.begin(); element != itemList.end(); ++element) {
		stocked = false;

		// Loop through all warehouses
		for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it) {

			// Check if item is in stock
			if (it->second->inStock(element->first)) {
				stocked = true;
				break;
			}
		}

		if (!stocked)
			cout << element->first << " " << items->getName(element->first) << endl;
	}
}

/*
 * Checks to see which items are fully stocked (meaning stocked in every warehouse)
 */
map<string, string> & warehouses::printFullystockedProducts() {
	cout << "Fully-Stocked Products:" << endl;

	bool stocked;

	map<string, item> itemList = items->getItemList();

	// Loop through each item in the fooditems
	for (std::map<string, item>::iterator element = itemList.begin(); element != itemList.end(); ++element) {
		stocked = true;

		// Loop through each warehouse
		for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it) {
			// Check if item is in stock
			if (!(it->second->inStock(element->first))) {
				stocked = false;
				break;
			}
		}
		// Check if it was in stock everywhere
		if (stocked)
			cout << element->first << " " << items->getName(element->first) << endl;
	}
}
