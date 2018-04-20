/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#include <vector>
#include <iostream>

using namespace std;

enum block_type {sum, sub, mul, idiv, less, great};

class Block_class {
protected:
  block_type type;
  vector <double> input_ports;
  double output_port;

public:
  block_type get_type_of_block();
  vector <double> get_inputs();
  double get_output();
  void set_input();

};
