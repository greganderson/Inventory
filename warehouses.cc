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


	for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it) {
		//it-> first => warehouse.

		//List of the item that the warehouse contains.
		//myvector = (it->first).InventoryList();
		vector<string> myvector = items->InventoryList();

		for (std::vector<string>::iterator element = myvector.begin(); element != myvector.end(); ++element)
		{
			//If the item is found go to
			// the next warehouse.
			if(it->second->inStock(*element))
			{
				continue;
			}
			else{
				listOfUnstocked[*element] = items->getName(*element);
			}
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



	//bool fullyStocked = true;
	for (map<string, warehouse*>::iterator it = whs->begin(); it != whs->end(); ++it) {
		// TODO: Need a way to loop through all of the fooditems, we have access through items, but
		// don't know what to do after that.
	  
	  /*
	  if (it->second->inStock(upc)){
	    
	  }
	  */
	      
	}
}
