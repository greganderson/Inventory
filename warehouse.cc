/*
 * Written by Greg Anderson and Jesus Zarate.
 */

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>

#include "warehouse.h"

using namespace std;

/*
 * Creates a warehouse with the name given.
 */
warehouse::warehouse(string _name, fooditems & f, date & d) {
	name = _name;
	*items = f;
	busiestDay = 0;
	*startDate = d;
	busiestDate = new date(startDate->getDate());
	currentDay = 0;
	inventory = new map<string, queue<int>* >;
	daysSinceBusiestDate = 0;
}

/*
 * Receive the number of items into the warehouse.  If it
 * hasn't been created yet, then it is created.
 */
void warehouse::receive(string upc, int amount) {
	// Add number of items received to current day transactions
	currentDay += amount;

	int sLife = items->getItem(upc).getShelfLife();

	// Check if inventory item hasn't been created yet
	if ((*inventory)[upc] == NULL)
		(*inventory)[upc] = new queue<int>;

	// Loop through and add the items to the inventory
	for (int i = 0; i < amount; i++)
		(*inventory)[upc]->push(sLife);
}

/*
 * Remove the number of items from the warehouse.  If there
 * are no items left, nothing happens.
 */
void warehouse::request(string upc, int amount) {
	// Add number of requests to current day transactions
	currentDay += amount;

	// Check if inventory item hasn't been created yet
	if ((*inventory)[upc] == NULL)
		return;

	for (int i = 0; i < amount; i++) {
		// If queue is empty, break out and be done with it
		if ((*inventory)[upc]->empty())
			return;

		(*inventory)[upc]->pop();
	}
}



/*
 * Goes through all inventory and reduces the items
 * remaining time by one day.  If something expires
 * (has 0 remaining days), it is removed from the queue.
 */
void warehouse::clearInventory() {
	daysSinceBusiestDate++;

	int count;	// Number of items inside a queue

	// Loop over all of the queues
	for (map<string, queue<int>* >::iterator it = inventory->begin(); it != inventory->end(); ++it) {
		count = (it->second)->size();
		for (int i = 0; i < count; i++) {
			// Get remaining days
			int x = (it->second)->front();
			(it->second)->pop();

			// Decrement remaining days
			x--;

			// Check if item expired, adding it back if it hasn't
			if (x != 0)
				(it->second)->push(x);
		}
	}

	// Check if we had a busier day than the busiest seen so far
	if (currentDay >= busiestDay) {
		busiestDay = currentDay;
		for (int i = 0; i < daysSinceBusiestDate; i++)
			busiestDate->advanceDate();
		daysSinceBusiestDate = 0;
	}

	// Reset the transaction counter
	currentDay = 0;
}

/*
 * Returns true if the item is in stock.
 */
bool warehouse::inStock(string upc) {
	// If the inventory doesn't exist, return false
	if ((*inventory)[upc] == NULL)
		return false;

	// Check if item is in stock
	if ((*inventory)[upc]->size() > 0)
		return true;

	// Item is out of stock
	return false;
}

/*
 * Prints out the busiest day.
 */
void warehouse::printBusiestDay() {
	cout << name << " " << busiestDate->getDate() << " " << busiestDay << endl;
}
