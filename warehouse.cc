#include <string>
#include <queue>
#include <map>

#include "warehouse.h"

using namespace std;

/*
 * Creates a warehouse with the name given.
 */
warehouse::warehouse(string _name) {
	name = _name;
	inventory = new map<string, queue<int>* >;
}

/*
 * Destructs the warehouse and its inventory.
 */
warehouse::~warehouse() {
	// TODO: Implement
}

/*
 * Receive the number of items into the warehouse.  If it
 * hasn't been created yet, then it is created.
 */
void warehouse::receive(string upc, int amount) {
	// TODO: Implement
}

/*
 * Remove the number of items from the warehouse.  If there
 * are no items left, nothing happens.
 */
void request(string upc, int amount) {
	// TODO: Implement
}
