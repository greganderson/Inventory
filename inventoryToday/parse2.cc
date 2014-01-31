#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <vector>
#include "warehouse.h"
#include "fooditems.h"
#include <cstdlib>

using namespace std;

struct Items
{

  string upc;
  int shelfLife;
  string name;

};

int main() {
	string filename = "data1.txt";
	ifstream in(filename.c_str());

	//The items will be mapped out to as the key being the
	// upc and the value being the contents of that item.
	map<string, Items> items;
	map<string, warehouse> Warehouses;
	warehouse Warehouse;

	while (true) {
		string line;
		getline(in, line);

		istringstream iss(line);

		// Example from http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
		vector<string> tokens;
		copy(istream_iterator<string>(iss),
				 istream_iterator<string>(),
				 back_inserter<vector<string> >(tokens));
		// End of example

		if (tokens.size() != 0) {
			if (tokens[0] == "FoodItem") {
				// TODO: Implement
			  cout << tokens[4] << endl;

			  //This will add the elements of the item to the food item class.
			  fooditems item(tokens[4], atoi((tokens[7]).c_str()), tokens[9]);

			  //This will add the elements fo the itme to the Items struct.
			  Items item1;
			  item1.upc =tokens[4];
			  item1.shelfLife = atoi((tokens[7]).c_str());
			  item1.name = tokens[9];

			  //Add the element to the items map.
			  items[tokens[4]] = item1;
			  
			}
			if (tokens[0] == "Warehouse") {
			  cout << tokens[0]<< tokens[2] << endl;

			  // warehouse Warehouse(tokens[2]);

				for (int i = 2; i < tokens.size(); i++) {
					// TODO: Implement
				}
			}
			if (tokens[0] == "Receive:") {
				// TODO: Implement
			  
			}
			if (tokens[0] == "Request:") {
				// TODO: Implement
			}
		}

		/*
		for (int i = 0; i < tokens.size(); i++) {
			if (tokens[i] == "FoodItem") {
				cout << "UPC: " << tokens[4] << endl;
				cout << "Shelf Life: " << tokens[7] << endl;
				cout << "Name: ";
				for (int j = 9; j < tokens.size(); j++)
					cout << tokens[j] << " ";
				cout << endl;
			}
		}
		*/

		if (in.fail())
			break;
	}

	in.close();

	return 0;
}
