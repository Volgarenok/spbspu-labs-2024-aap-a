#ifndef DYNAMICSTRINGS_H
#define DYNAMICSTRINGS_H
#include <iostream>

namespace savintsev
{
  char * inputEndlessStr(std::istream & in);
  char * increaseStrSize(char * old, size_t m);
  char * allocMemoryStr(size_t capacity);
  int getNumIdenticalInRow(char * c);
}

#endif
