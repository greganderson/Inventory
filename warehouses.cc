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
warehouses::warehouses(fooditems & f) {
	this->items = &f;
	whs = new map<string, warehouse*>;
	requests = new map<string, queue<Request>* >;
}

void warehouses::setDate(date &d) {
	this->start = &d;
	for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it)
		it->second->setStartDate(d);
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
warehouse & warehouses::getWarehouse(string name) {
	return *(*whs)[name];
}

/*
 * Requests waiting to be processed after the receives 
 * have been processed.
 */
void warehouses::pendingRequest(string wh, string upc, int amount){

  if((*requests)[wh] == NULL){
    (*requests)[wh] = new queue<Request>;
  }

  Request *request = new Request(wh, upc, amount);

  //Add the request to the queue of requests for that warehouse.
  (*requests)[wh]->push(*request);

  int i = (*requests)[wh]->size();
  string hello;

}

/*
 * Process the all of the requests for each warehouse
 */
void warehouses::processRequests(){

  for(map<string, queue<Request>* >::iterator it = requests->begin(); it != requests -> end(); ++it){
    // Pop the request off the queue
    queue<Request>* rqst = (it->second);
    int i = rqst->size();
    
    while(!rqst->empty()){
      Request r = rqst->front();
      rqst->pop();
      getWarehouse(it->first).request(r.getUpc(), r.getAmount());
    }
  }

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

/*
 * Clear each warehouses inventory.
 */
void warehouses::advanceWarehouses() {
	for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it)
		it->second->clearInventory();
}

/*
 * Updates the last day
 */
void warehouses::endOfInventory(){
  for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it)
    it->second->end();  
}

/*
 * Prints the busiest day for each warehouse
 */
void warehouses::printBusiestDays() {
	for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it)
		it->second->printBusiestDay();
}
