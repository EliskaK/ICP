/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/

#include "sumblock.hpp"

Sum_block_class::Sum_block_class(){
  this->type = sum;
}

double Sum_block_class::count(){
  double res, temp = 0.0;
  int size = input_ports.size();
  for (int i = 0; i < size; i++) {
    temp = temp + input_ports.at(i);
  }
  res = temp;
  cout << res << endl;
  return res;
}
