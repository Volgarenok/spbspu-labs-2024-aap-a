#ifndef MAKING_NEW_STRING_HPP
#define MAKING_NEW_STRING_HPP
#include <cstddef>

namespace petrov
{
  char * inputCString(char * string, size_t & capacity);
  char * makeNewCStringOutOfTwo(char * new_cstring, const char * string_1, const char * string_2, const size_t capacity);
}
#endif
