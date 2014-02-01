#include <iostream>
#include <string>
#include <queue>

#ifndef FOODITEM_H
#define FOODITEM_H

using namespace std;


class fooditem
{
	public:
		fooditem(string upc_code, int shelf_life, string name);
		~fooditem();
		std::string getUPC();
		std::string getName();
		int getShelfLife();

	private:
		string upc;
		int shelf_life;
		string name;

};
#endif
