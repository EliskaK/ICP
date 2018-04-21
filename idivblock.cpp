/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/

#include "idivblock.hpp"

Idiv_block_class::Idiv_block_class(){
  this->type = idiv;
}

double Idiv_block_class::count(){
  double res;
  int size = input_ports.size();
  if(size != 2){
    cerr << "ERROR: U bloku pro deleni mohou byt na vstupu pouze dva porty!" << endl;
    exit(10);
  }
  if(input_ports.at(1) == 0){
    cerr << "ERROR: Deleni nulou!" << endl;
    exit(10);
  }
  res = input_ports.at(0) / input_ports.at(1);
  return res;
}
