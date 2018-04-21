/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#ifndef IDIVBLOCK_H
#define IDIVBLOCK_H

#include <iostream>
#include "block.hpp"

using namespace std;

class Idiv_block_class : public Block_class {
public:
  Idiv_block_class();
  virtual ~Idiv_block_class (){}

  double count();
};
#endif //IDIVBLOCK_H
