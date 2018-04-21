/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#ifndef MULBLOCK_H
#define MULBLOCK_H

#include <iostream>
#include "block.hpp"

using namespace std;

class Mul_block_class : public Block_class {
public:
  Mul_block_class();
  virtual ~Mul_block_class (){}

  double count();
};
#endif //MULBLOCK_H
