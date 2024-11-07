#ifndef DYNAMICSTRINGS_H
#define DYNAMICSTRINGS_H
#include <iostream>

namespace savintsev
{
  char * inputEndlessString(std::istream & in);
  char * increaseStringSize(char * old, size_t m);
  size_t getNumIdenticalInRow(char * c);
}

#endif
