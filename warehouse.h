#include <string>
#include <map>
#include <queue>

#ifndef WAREHOUSE_H
#define WAREHOUSE_H

class warehouse {

	private:
		std::map<std::string, std::queue<int>* > inventory;	// Map of items, <UPC => Inventory
		
	public:
		warehouse();
		void receive(std::string upc, std::string amount);
		void request(std::string upc, int amount);
};
#endif
