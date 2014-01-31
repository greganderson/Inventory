#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include <utility>

#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

class inventory
{

 public: 
  inventory();
  void insert(string upc, string name);

 private:
  map<string, string> fooditem;


};
#endif
