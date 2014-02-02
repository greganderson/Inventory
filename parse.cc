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

int main(string argc, char* argv[]) {

        string filename = argv[1];
	ifstream in(filename.c_str());



	fooditems fooditems1;

	date start_date;

	//The list of the warehouses.
	warehouses WH(fooditems1, start_date);

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
			  date Date(tokens[2]);
			  start_date = Date;
			}

			if (tokens[0] == "FoodItem") {
				// TODO: Implement
			  cout << tokens[4] << endl;

			  //This will add the elements of the item to the food item class.
			  item item1(tokens[4], atoi((tokens[7]).c_str()), tokens[9]);
	        
			  //The list of the food items
			  // fooditems fooditems1;	       

			  //Add to the Fooditems class.
			  fooditems1.addItem(tokens[4], item1);
			  
			}
			if (tokens[0] == "Warehouse") {
				string place = "";
				for (int i = 2; i < tokens.size(); i++) {
					place += tokens[i] + " ";
				}
				//Make the new Warehouse and tell it what food items it could have.
				warehouse Warehouse(place, fooditems1, start_date);
				
			}
			if(tokens[0] == "Receive:"){
			        //This is not working because the get function is constant.
			        WH.getWarehouse(tokens[3]).receive(tokens[1], atoi((tokens[2]).c_str()));
			  
			  }
			if (tokens[0] == "Request:") {
				//Not working because get is constant.
			        WH.getWarehouse(tokens[3]).receive(tokens[1], atoi((tokens[2]).c_str()));
			}
			//Advance the effective date by one day.
			if(tokens[0] == "Next"){
			        //
			  
			}
			if(tokens[0] == "End:"){
			  break;
			}
		}

		//************REPORT*************\\
		//Unstocked products
		WH.unstockedProducts();

		WH.fullystockedProducts();

		if (in.fail())
			break;
	}

	in.close();

	return 0;
}
