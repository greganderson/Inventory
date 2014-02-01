#include <string>
#include <map>

#ifndef INVENTORY_H
#define INVENTORY_H

class inventory
{

	public: 
		inventory();
		void insert(std::string upc, std::string name);

	private:
		std::map<std::string, std::string> fooditem;
};
#endif
