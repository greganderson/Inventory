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
	int C = 0;
	bool process_requests = false;
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
				string place = "";
				for (int i = 3; i < tokens.size(); i++) {
					place += tokens[i] + " ";
				}

				if(place == ("Chandler ") && tokens[1] == "0814194965"){
				  string here;
				}
				WH->getWarehouse(place).receive(tokens[1], atoi((tokens[2]).c_str()));
			}
			if (tokens[0] == "Request:") {

				string place = "";
				for (int i = 3; i < tokens.size(); i++) {
					place += tokens[i] + " ";
				}
				
				//Store the requests in temporary container 
				// while the receives are being processed.
				//Uncomment for version 1.2
				WH->pendingRequest(place, tokens[1], atoi((tokens[2]).c_str()));

				//if(place == ("Chandler ") && tokens[1] == "0814194965"){
				//   string here;
				//}
				
				//Uncomment for the version of warehouse before update which is version 1.1.
				//WH->getWarehouse(place).request(tokens[1], atoi((tokens[2]).c_str()));
			}
			//Advance the effective date by one day.
			if(tokens[0] == "Next") {
			  
			  //We process the request at this point
			  //Uncomment for version 1.2
			  WH->processRequests();

			  //Clear the inventory of expired items and advance day.
			  WH->advanceWarehouses();
			}

			if(tokens[0] == "End") {

			  //Comment out for version of warehouse before update which is version 1.1.
			  //Uncomment for version 1.2
			  WH->processRequests();

			  WH->endOfInventory();
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

	start_date = NULL;
	fooditems1 = NULL;
	WH = NULL;

	delete start_date;
	delete fooditems1;
	delete WH;

	return 0;
}
