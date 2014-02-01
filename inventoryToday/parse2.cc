#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <vector>
#include "warehouse.h"
#include "items.h"
#include <cstdlib>
#include <map>

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
	//map<string, fooditems*> *items = new map<string, fooditems*>;

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
			  item item1(tokens[4], atoi((tokens[7]).c_str()), tokens[9]);
	        
		       
			  //Add to the Fooditems class.
			  
			}
			if (tokens[0] == "Warehouse") {

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

		{
		  //queue<string> *q = new queue<string>;
		  //map<string, queue<string>* > *mq = new map<string, queue<string>* >;
 
		  //q->push("Hello");
 
		  //mq->insert(pair<string, queue<string>* >("whatever", q));
 
		  // for (map<string, fooditems >::iterator it = items->begin(); it != items->end(); ++it) {
		  //   cout << "[" << it->first << ", " << (it->second).getName() << "]" << endl;
		  // }
 
		  //cout << (*items)["0353264991"].getName() << endl;
 
		}

		if (in.fail())
			break;
	}

	in.close();

	return 0;
}
