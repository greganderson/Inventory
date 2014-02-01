#include <iostream>
#include <string>
#include <queue>
#include <map>

#include "warehouse.h"

#ifndef WAREHOUSES_H
#define WAREHOUSES_H

class warehouses
{

	private:
		std::map<std::string, warehouse*> *whs;

	public:
		warehouses();
		~warehouses();
		void addWarehouse(std::string name);
		const warehouse & getWarehouse(std::string name);

};
#endif
