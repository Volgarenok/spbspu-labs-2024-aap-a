#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

namespace smirnov
{
  char * getLine(std::istream & in, char stop);
  char * uniString(char * str1, const char * str2);
}
