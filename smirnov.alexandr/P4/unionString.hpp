#ifndef UNIONSTRING_HPP
#define UNIONSTRING_HPP
#include <iostream>

namespace smirnov
{
  char * getLine(std::istream & in, char stop);
  char * uniString(char * result_str, const char * str1, const char * str2);
}
#endif
