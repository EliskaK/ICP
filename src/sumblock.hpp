/*
* ICP 2018 - Block Editor
* FIT VUT
* Eliska Kadlecova, Daniel Doubek
*/
#ifndef SUMBLOCK_H
#define SUMBLOCK_H

#include <iostream>
#include "block.hpp"

using namespace std;

class Sum_block_class : public Block_class {
public:
  Sum_block_class();
  virtual ~Sum_block_class (){}

  double count();
};
#endif //SUMBLOCK_H
