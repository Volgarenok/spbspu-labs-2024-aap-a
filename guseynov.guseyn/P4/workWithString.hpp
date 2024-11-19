#ifndef WORKWITHSTRING_HPP
#define WORKWITHSTRING_HPP

#include <iostream>
#include <cstddef>

namespace guseynov
{
  char * getLine(std::istream & in, char stop);
  char * getNewArr(char *arr, size_t size, size_t step);
  size_t identifyUniqueChar(const char *inputString, const char *uniqueChars, const size_t num);
}
#endif
