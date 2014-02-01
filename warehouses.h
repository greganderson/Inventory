#include <iostream>
#include <string>
#include <queue>
#include <map>

#ifndef WAREHOUSES_H
#define WAREHOUSES_H

class warehouses
{

	private:
		std::string name;
		std::map<std::string, std::map<std::string, std::queue<std::string>* >* > whs;

	public:
		warehouses(std::string);
		void addWarehouse(std::string name);

};
#endif
