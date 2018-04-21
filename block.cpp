/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/

#include "block.hpp"

block_type Block_class::get_type_of_block(){
  return type;
}

vector <double> Block_class::get_inputs(){
  return input_ports;
}

double Block_class::get_output(){
  return output_port;
}

void Block_class::set_input(double inpt){
  input_ports.push_back(inpt);
}

void Block_class::set_output(double outpt){
  this->output_port = outpt;
}
