#ifndef PROCESSLINE_HPP
#define PROCESSLINE_HPP
#include <iostream>

namespace krylov
{
  char * inLine(std::istream & in);
  char * resizeArray(char * oldArray, size_t newCapacity);
}

#endif
