#include <iostream>
#include <string>
#include "fooditem.h"


using namespace std;

fooditem::fooditem()
{

  this->upc_code = "";
  this->shelf_life = 0;
  this->name = "";

}

void fooditem::upc(string upc_code)
{
  this->upc_code = upc_code;
}

void fooditem::s_life(int shelf_life)
{
  this->shelf_life = shelf_life;
}

void fooditem::Name(string name)
{
  this->name = name;
}

string fooditem::getUPC()
{
  return this-> upc_code;
}

string fooditem::getName()
{
  return this-> name;
}

int fooditem::getSLife()
{
  return this-> shelf_life;
}
