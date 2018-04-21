/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/

#include "subblock.hpp"

Sub_block_class::Sub_block_class(){
  this->type = sub;
}

double Sub_block_class::count(){
  double res, temp = 0.0;
  int size = input_ports.size();
  for (int i = 0; i < size; i++) {
    temp = temp - input_ports.at(i);
  }
  res = temp;
  return res;
}
