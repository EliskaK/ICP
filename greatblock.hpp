/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#ifndef GREATBLOCK_H
#define GREATBLOCK_H

#include <iostream>
#include "block.hpp"

using namespace std;

class Great_block_class : public Block_class {
public:
  Great_block_class();
  virtual ~Great_block_class (){}

  double count();
};
#endif //GREATBLOCK_H
