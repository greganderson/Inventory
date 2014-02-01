#include <iostream>
#include <string>
#include <queue>
#include <map>

#ifndef WAREHOUSES_H
#define WAREHOUSES_H

class warehouses
{

	private:
		std::map<std::string, std::map<std::string, std::queue<int>* >* > whs;

	public:
		warehouses();
		void addWarehouse(std::string name);

};
#endif
