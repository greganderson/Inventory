#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

class warehouse
{

 private:
  string name;
  vector<string> items;
  map<string, vector<string> > wh;

 public:
  warehouse();
  void addWarehouse(string name);
  void addItem(std::string name, std::string upc);
  void receive(string upc, int amount);
  void request(string upc, int amount);

};
