#include <iostream>
#include <string>
#include <map>
#include "requests.h"
#include "warehouse.h"

Request::Request(std::string place, std::string upc, int amount){
  
  this->place = place;
  this->upc = upc;
  this->amount = amount;


}

std::string Request::getUpc(){
  return this->upc;
}

int Request::getAmount(){
  return this->amount;
}
