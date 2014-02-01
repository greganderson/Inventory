#include <string>
#include <map>
#include <queue>

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class warehouse {

	private:
		std::map<std::string, std::queue<int>* > *inventory;	// Map of items, <UPC => Inventory
		std::string name;
		
	public:
		warehouse(std::string);
		~warehouse();
		void receive(std::string upc, int amount);
		void request(std::string upc, int amount);
};
#endif
