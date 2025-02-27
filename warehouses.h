/*
 * Written by Greg Anderson and Jesus Zarate.
 */

#include <iostream>
#include <string>
#include <queue>
#include <map>

#include "warehouse.h"
#include "fooditems.h"
#include "date.h"
#include "requests.h"

#ifndef WAREHOUSES_H
#define WAREHOUSES_H

class warehouses
{

	private:
		std::map<std::string, warehouse*> *whs;

		//Map to keep track of requests
		std::map<std::string, std::queue<Request>* > *requests;
		fooditems *items;
		date *start;

	public:
		warehouses(fooditems &);
		void addWarehouse(std::string name);
		warehouse & getWarehouse(std::string name);
		std::map<std::string, std::string> & printUnstockedProducts();
		std::map<std::string, std::string> & printFullystockedProducts();
		void advanceWarehouses();
		void printBusiestDays();
		void setDate(date &);
		void pendingRequest(std::string wh, std::string upc, int amount);
		void processRequests();
		void endOfInventory();


};
#endif
