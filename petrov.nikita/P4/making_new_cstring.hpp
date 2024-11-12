#ifndef MAKING_NEW_STRING_HPP
#define MAKING_NEW_STRING_HPP
#include <iostream>

namespace petrov 
{
  char * inputCSring(char * string, size_t & length);
  char * makeNewCStringOutOfTwo(char * new_cstring, const char * string_1, const char * string_2,
                                const size_t length_1, const size_t length_2);
  void outputNewCString(char * new_cstring);
}
#endif
