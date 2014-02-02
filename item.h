/*
 * Written by Greg Anderson and Jesus Zarate.
 */

#include <string>

#ifndef ITEM_H
#define ITEM_H
class item
{
	friend class warehouse;

	private:
		std::string upc;
		int shelfLife;
		std::string name;


	public:
		item();
		item(std::string upc, int sl, std::string name);
		std::string getUpc();
		int getShelfLife();
		std::string getName();
};
#endif
