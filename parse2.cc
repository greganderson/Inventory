#include <iostream>
#include <sstream>
#include <iterator>
#include <fstream>
#include <vector>
#include <map>


using namespace std;

int main() {
	string filename = "data1.txt";
	ifstream in(filename.c_str());

	map<string, string> fooditem;
	map<string, int> quantity;
	
	//inventory inv;

	while (true) {
		string line;
		getline(in, line);

		istringstream iss(line);

		// Example from http://stackoverflow.com/questions/236129/how-to-split-a-string-in-c
		vector<string> tokens;
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string> >(tokens));
		// End of example

		if (tokens.size() != 0) {
			if (tokens[0] == "FoodItem") {
				// TODO: Implement

			  fooditem[tokens[4]] = tokens[9];
			  quantity[tokens[4]] =  atoi((tokens[7]).c_str());
			}
			if (tokens[0] == "Warehouse") {
				string place = "";
				for (int i = 2; i < tokens.size(); i++) {
					place += tokens[i] + " ";
				}
				cout << place << endl;
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
