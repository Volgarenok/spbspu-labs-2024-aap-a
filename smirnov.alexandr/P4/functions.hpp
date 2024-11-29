#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>
#include <iostream>

namespace smirnov
{
  char * getLine(std::istream & in, char stop);
  char * uniString(char * result_str, const char * str1, const char * str2);
}
#endif
