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
 * Returns the warehouse asked for.
 */
void::unstockedProducts(fooditems items) {
  //For every item check in every warehouse's items list to see if it 
  //exists.
}
