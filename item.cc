#include <iostream>
#include <string>
#include "item.h"

using namespace std;

item::item()
{
    upc = "";
    shelfLife = 0;
    name = "";
}

//Copy constructor.
item::item(const item & other)
{
  this->upc = other.upc;
  this->shelfLife = other.shelfLife;
  this->name = other.name;
  *this = other;

}

item::item(string upc, int shelfLife, string name)
{
	this-> upc = upc;
	this-> shelfLife = shelfLife;
	this-> name = name;
}

string item::getUpc()
{
	return upc;
}

int item::getShelfLife()
{
	return shelfLife;
}

string item::getName()
{
	return name;
}

