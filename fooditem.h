#include <iostream>
#include <string>
#include <queue>

#ifndef FOODITEM_H
#define FOODITEM_H

using namespace std;

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
		void Items(string upc, int sLife, string name);
		/* friend Rectangle duplicate (const Rectangle&) */;


	private:
		string upc_code;
		int shelf_life;
		string name;

};
#endif
