#ifndef PROCESSLINE_HPP
#define PROCESSLINE_HPP
#include <iostream>

namespace krylov
{
  char * inputLine(std::istream & in);
  char * replaceArray(char * oldArray, size_t newCapacity);
}

#endif
