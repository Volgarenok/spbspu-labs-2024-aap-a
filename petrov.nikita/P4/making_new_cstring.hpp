#ifndef MAKING_NEW_STRING_HPP
#define MAKING_NEW_STRING_HPP
#include <iostream>

namespace petrov
{
  char * inputCString(std::istream & in, size_t & capacity);
  char * makeNewCStringOutOfTwo(const char * string_1, const char * string_2, const size_t capacity);
}
#endif
