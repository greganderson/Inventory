/*
 * Written by Greg Anderson and Jesus Zarate.
 */

#include <string>
#include <map>
#include <queue>
#include <vector>
#include "fooditems.h"
#include "item.h"
#include "date.h"
#include "requests.h"

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class item;

class warehouse {


	private:
		std::map<std::string, std::queue<int>* > *inventory;	// Map of items, <UPC => Inventory>
		
		std::string name;	// Name of warehouse
		fooditems *items;	// List of fooditems
		int busiestDay;		// Busiest day seen so far
		int currentDay;		// Amount of transactions seen on current day
		date *startDate;	// Start date
		date *busiestDate;	// The actual date of the busiest day
		date *currentDate;      // The current date.
		int daysSinceBusiestDate;	// Number of days since the last busiest date
		
	public:
		warehouse(std::string, fooditems &);
		void receive(std::string upc, int amount);
		void request(std::string upc, int amount);
		void clearInventory();
		bool inStock(std::string);
		void printBusiestDay();
		void setStartDate(date &);
		void end();


};
#endif
