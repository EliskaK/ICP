/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#ifndef LESSBLOCK_H
#define LESSBLOCK_H

#include <iostream>
#include "block.hpp"

using namespace std;

class Less_block_class : public Block_class {
public:
  Less_block_class();
  virtual ~Less_block_class (){}

  double count();
};
#endif //LESSBLOCK_H
