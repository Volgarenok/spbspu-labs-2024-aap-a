#ifndef SHRSYM_UNITWO_HPP
#define SHRSYM_UNITWO_HPP

#include <iostream>

namespace sharifullina
{
  char * inputString(std::istream & in, char stop);
  char * shrSym(const char * str1, const char * str2, char * res);
  char * uniTwo(const char * str1, const char * str2, char * res);
}
#endif
