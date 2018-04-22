/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#include <iostream>

#include "block.hpp"
#include "sumblock.hpp"
#include "greatblock.hpp"
#include "lessblock.hpp"
#include "idivblock.hpp"
#include "mulblock.hpp"
#include "subblock.hpp"
#include "scheme.hpp"

using namespace std;

int main() {
  //Scheme_class scheme1;
  Sub_block_class *block1 = new Sub_block_class();
  Idiv_block_class *block2 = new Idiv_block_class();
  double connect1 = 1.0;
  double connect2 = 2.0;

  //scheme1.add_block(block1);
  cout << "Type of block: " << block1->get_type_of_block() << endl;

  block1->set_input(1.1);
  block1->set_input(connect2);

  block2->set_input(connect1);
  block2->set_input(2.6);

  block1->set_output(block1->count());
  block2->set_output(block2->count());
  cout << "Output: " << block1->get_output() << endl;
  cout << "Output: " << block2->get_output() << endl;

  return 0;
}
