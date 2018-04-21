/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#ifndef SUBBLOCK_H
#define SUBBLOCK_H

#include <iostream>
#include "block.hpp"

using namespace std;

class Sub_block_class : public Block_class {
public:
  Sub_block_class();
  virtual ~Sub_block_class (){}

  double count();
};
#endif //SUBBLOCK_H
