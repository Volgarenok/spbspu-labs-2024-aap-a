#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP
#include <iostream>

namespace ivanova
{
  char* getLine(std::istream& in);
  char* moreSpace(const char* string, size_t newSize);
}

#endif
