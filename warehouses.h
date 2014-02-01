#include <iostream>
#include <string>
#include <queue>
#include <map>

#include "warehouse.h"
#include "fooditems.h"

#ifndef WAREHOUSES_H
#define WAREHOUSES_H

class warehouses
{

	private:
		std::map<std::string, warehouse*> *whs;
		fooditems *items;

	public:
		warehouses(fooditems &);
		~warehouses();
		void addWarehouse(std::string name);
		const warehouse & getWarehouse(std::string name);

};
#endif
