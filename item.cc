#include <string>
#include "item.h"

using namespace std;

item::item(string upc, int shelfLife, string name)
{
	this->upc = upc;
	this-> shelfLife = shelfLife;
	this-> name = name;
}

std::string item::getUpc()
{
	return this->upc;
}

int item::getShelfLife()
{
	return shelfLife;
}

std::string item::getName()
{
	return name;
}

