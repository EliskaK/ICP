/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/

#include "greatblock.hpp"

Great_block_class::Great_block_class(){
  this->type = great;
}

double Great_block_class::count(){
  double res;
  int size = input_ports.size();
  if(size != 2){
    cerr << "ERROR: U bloku pro porovnani mohou byt na vstupu pouze dva porty!" << endl;
    exit(10);
  }
  if(input_ports.at(0) >= input_ports.at(1)){
    res = input_ports.at(0);
  }
  else if (input_ports.at(1) > input_ports.at(0)){
    res = input_ports.at(1);
  }
  return res;
}
