#include <iostream>
#include <string>

#ifndef ITEM_H
#define ITEM_H
class item
{

	friend class warehouse.h

	private:
		item();
		std::string upc ;
		int shelfLife;
		std::string name;


	public:
		item(std::string upc, int sl, std::string name);
		std::string getUpc();
		int getShelfLife();
		std::string getName();

};
#endif
