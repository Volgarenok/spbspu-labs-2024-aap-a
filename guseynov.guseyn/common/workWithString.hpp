#ifndef WORKWITHSTRING_HPP
#define WORKWITHSTRING_HPP

#include <iostream>
#include <cstddef>

namespace guseynov
{
  char * getLine(std::istream & in, size_t & stringLength);
  char * expandMassive(char *arr, size_t size, size_t step);
  size_t determiningNumOfLetters(const char *inputString, size_t stringLength);
}
#endif
