/*
 * Written by Greg Anderson and Jesus Zarate.
 */

#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <vector>
#include "warehouse.h"
#include "warehouses.h"
#include "item.h"
#include "fooditems.h"
#include <cstdlib>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
	string filename = argv[1];
	ifstream in(filename.c_str());

	fooditems *fooditems1 = new fooditems();

	date *start_date;

	//The list of the warehouses.
	warehouses *WH = new warehouses(*fooditems1);


	while (true) {
		string line;
		getline(in, line);

		istringstream iss(line);

		// Example from http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
		vector<string> tokens;
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string> >(tokens));
		// End of example


		if (tokens.size() != 0) {

			if(tokens[0] == "Start"){
				start_date = new date(tokens[2]);
				WH->setDate(*start_date);
			}

			if (tokens[0] == "FoodItem") {
				// Get name
				string name = "";
				for (int i = 9; i < tokens.size(); i++) {
					name += tokens[i] + " ";
				}

				//This will add the elements of the item to the food item class.
				item item1(tokens[4], atoi((tokens[7]).c_str()), name);

				//The list of the food items
				// fooditems fooditems1;	       

				//Add to the Fooditems class.
				fooditems1->addItem(tokens[4], item1);

			}
			if (tokens[0] == "Warehouse") {
				string place = "";
				for (int i = 2; i < tokens.size(); i++) {
					place += tokens[i] + " ";
				}
				//Make the new Warehouse and tell it what food items it could have.
				WH->addWarehouse(place);

				
			}
			if(tokens[0] == "Receive:"){
				//This is not working because the get function is constant.
				string place = "";
				for (int i = 3; i < tokens.size(); i++) {
					place += tokens[i] + " ";
				}
				WH->getWarehouse(place).receive(tokens[1], atoi((tokens[2]).c_str()));
			}
			if (tokens[0] == "Request:") {
				string place = "";
				for (int i = 3; i < tokens.size(); i++) {
					place += tokens[i] + " ";
				}
				WH->getWarehouse(place).request(tokens[1], atoi((tokens[2]).c_str()));
			}
			//Advance the effective date by one day.
			if(tokens[0] == "Next") {
				WH->advanceWarehouses();
			}

			if(tokens[0] == "End") {
			  break;
			}
		}

		if (in.fail())
			break;
	}

	in.close();

	/************REPORT*************/
	cout << "Report by Greg Anderson and Jesus Zarate\n" << endl;

	WH->printUnstockedProducts();

	cout << endl;

	WH->printFullystockedProducts();

	cout << endl;

	cout << "Busiest Days:" << endl;

	WH->printBusiestDays();

	delete start_date;
	delete fooditems1;
	delete WH;
	start_date = NULL;
	fooditems1 = NULL;
	WH = NULL;

	return 0;
}
