#include <iostream>
#include <string>
#include "fooditems.h"

fooditems::item(string upc, int shelfLife, string name)
{
	this-> upc = upc;
	this-> shelfLife = shelfLife;
	this-> name = name;
}

string fooditems::getUpc()
{
	return upc;
}

string fooditems::getShelfLife()
{
	return shelfLife;
}

string fooditems::getName()
{
	return name;
}

