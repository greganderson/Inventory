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
warehouses::warehouses(fooditems & f) {
	*items = f;
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
	(*whs)[name] = new warehouse(name, *items);
}

/*
 * Returns the warehouse asked for.
 */
const warehouse & warehouses::getWarehouse(string name) {
	return *(*whs)[name];
}
