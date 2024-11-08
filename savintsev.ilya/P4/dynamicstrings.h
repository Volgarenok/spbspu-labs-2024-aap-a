#ifndef DYNAMICSTRINGS_H
#define DYNAMICSTRINGS_H
#include <iostream>

namespace savintsev
{
  char * inputEndlessStr(std::istream & in);
  char * increaseStrSize(char * old, size_t m);
  char * allocMemoryStr(size_t capacity);
  size_t getNumIdenticalInRow(char * c);
}

#endif
