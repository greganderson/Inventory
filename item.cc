#include <iostream>
#include <string>
#include "item.h"

item::item(std::string upc, int shelfLife, std::string name)
{
	this-> upc = upc;
	this-> shelfLife = shelfLife;
	this-> name = name;
}

std::string item::getUpc()
{
	return upc;
}

int item::getShelfLife()
{
	return shelfLife;
}

std::string item::getName()
{
	return name;
}

