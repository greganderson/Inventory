/*
 * Written by Greg Anderson and Jesus Zarate.
 */

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>

#include "warehouse.h"
#include "requests.h"

using namespace std;

/*
 * Creates a warehouse with the name given.
 */
warehouse::warehouse(string _name, fooditems & f) {
	name = _name;
	this->items = &f;
	busiestDay = 0;
	currentDay = 0;
	inventory = new map<string, queue<int>* >;

	daysSinceBusiestDate = 0;
	
}

void warehouse::setStartDate(date &d) {
        this->startDate = new date(d.getDate());
	this->currentDate = new date(d.getDate());
	//this->busiestDate = &d;
	/* HERE: Passing the reference would make the date change for every warehouse */
	this->busiestDate = new date(d.getDate());
}
/*
 * Receive the number of items into the warehouse.  If it
 * hasn't been created yet, then it is created.
 */
void warehouse::receive(string upc, int amount) {
	// Add number of items received to current day transactions
	currentDay += amount;

	if(upc == "0814194965"){
	  cout<< upc << " " << amount << endl;
	}

	int sLife = items->getItem(upc).getShelfLife();

	// Check if inventory item hasn't been created yet
	if ((*inventory)[upc] == NULL)
		(*inventory)[upc] = new queue<int>;

	  int s = (*inventory)[upc]->size();
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
	  int s = (*inventory)[upc]->size();

	  

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
		// Check to make sure there is something to check
	        if ((it->second) == NULL)
		  continue;

		count = (it->second)->size();

		for (int i = 0; i < count; i++) {
		  // Get remaining days
		  int x = (it->second)->front();
		  (it->second)->pop();

		  // Decrement remaining days
		  x--;

		  // Check if item expired, adding it back if it hasn't
		  if (x != 0){
		    (it->second)->push(x);
		  }
		}
	}

	// Check if we had a busier day than the busiest seen so far
	if (currentDay >= busiestDay) {
		busiestDay = currentDay;
		for (int i = 0; i < daysSinceBusiestDate; i++) {
		  busiestDate = new date(*currentDate);
		  currentDate->advanceDate();
		}
		daysSinceBusiestDate = 0;
	}

	// Reset the transaction counter
	currentDay = 0;

}

void warehouse::end(){
  daysSinceBusiestDate++;

  // Check if we had a busier day than the busiest seen so far
  if (currentDay >= busiestDay) {
    busiestDay = currentDay;
    for (int i = 0; i < daysSinceBusiestDate; i++) {
      busiestDate = new date(*currentDate);
      currentDate->advanceDate();
    }
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
  if((*inventory)[upc] != NULL){

    if((*inventory)[upc]->size() > 0){
    //if((*inventory)[upc]->front() > 0){
	return true;
    }
    else{
      return false;
    }
  }
  else{
    // Item is out of stock
    return false;
  }
}

/*
 * Prints out the busiest day.
 * For each warehouse.
 */
void warehouse::printBusiestDay() {
	cout << name << " " << busiestDate->getDate() << " " << busiestDay << endl;
}
