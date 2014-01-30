#include <iostream>
#include <string>

#ifndef FOODITEM_H
#define FOODITEM_H

class fooditem
{

	public:
		//void fooditem(string upc_code, int shelf_life, string name);
		fooditem();
		void upc(string upc_code);
		void s_life(int shelf_life);
		void Name(string name);
		string getUPC();
		string getName();
		int getSLife();

	private:
		string upc_code;
		int shelf_life;
		string name;

};
#endif
