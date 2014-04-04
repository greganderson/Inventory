#include <iostream>
#include <string>
#include <map>

#ifndef REQUEST_H
#define REQUEST_H

class warehouse;

class Request{

 private:
  std::string place;
  std::string upc;
  int amount;
 public:
  Request(std::string place, std::string upc, int amount);
  std::string getUpc();
  int getAmount();

};

#endif
