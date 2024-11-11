#ifndef WORKWITHSTRING_HPP
#define WORKWITHSTRING_HPP
#include <iostream>
#include <cstddef>
namespace guseyn
{
  void copyarr(const char *arr, char *arrcopy, size_t size);
  char * inputLine(std::istream & in, char stop);
  size_t identifyUniqueChar(char *inputString, char *uniqueChars, size_t num);
}
#endif
