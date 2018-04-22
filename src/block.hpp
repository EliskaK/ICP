/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <iostream>

using namespace std;

enum block_type {NONE, sum, sub, mul, idiv, lt, gt};

class Block_class {
protected:
  block_type type = NONE;
  vector <double> input_ports;
  double output_port;

public:
  Block_class(){}
  ~Block_class(){}
  block_type get_type_of_block();
  vector <double> get_inputs();
  double get_output();
  virtual void set_input(double inpt);
  void set_output(double outpt);
};

#endif //BLOCK_H
