#ifndef DYNAMICSTRINGS_H
#define DYNAMICSTRINGS_H
#include <iostream>

namespace savintsev
{
  char * inputNewlineTerminatedStr(std::istream & in);
  char * createEnlargedCopiedStr(char * old, size_t m);
  size_t getNumIdenticalInRow(char * c);
}

#endif
