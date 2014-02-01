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
		warehouses(fooditems &, date &);
		~warehouses();
		void addWarehouse(std::string name);
		const warehouse & getWarehouse(std::string name);

};
#endif
