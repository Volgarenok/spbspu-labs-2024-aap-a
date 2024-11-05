#ifndef DYNAMICSTRINGS_H
#define DYNAMICSTRINGS_H
#include <iostream>

namespace savintsev
{
  char * inputEndlessString(std::istream & in, char endChar);
  char * increaseStringSize(char * old, size_t m);
}

#endif
