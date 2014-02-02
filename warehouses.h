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

#ifndef WAREHOUSES_H
#define WAREHOUSES_H

class warehouses
{

	private:
		std::map<std::string, warehouse*> *whs;
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

};
#endif
