#ifndef WORKWITHSTRING_HPP
#define WORKWITHSTRING_HPP

#include <iostream>
#include <cstddef>

namespace guseynov
{
  char * getLine(std::istream & in);
  void expandMassive(char *arr, size_t & size, size_t step);
}
#endif
