#ifndef MAKING_NEW_STRING_HPP
#define MAKING_NEW_STRING_HPP
#include <iostream>

namespace petrov
{
  char * inputCString(std::istream & in, size_t & capacity);
  char * combineFirstCStrAndDigitsFromSecond(char * new_cstring, const char * string_1, const char * string_2);
}
#endif
