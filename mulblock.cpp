/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/

#include "mulblock.hpp"

Mul_block_class::Mul_block_class(){
  this->type = mul;
}

double Mul_block_class::count(){
  double res, temp = 1.0;
  int size = input_ports.size();
  for (int i = 0; i < size; i++) {
    temp = temp * input_ports.at(i);
  }
  res = temp;
  return res;
}
