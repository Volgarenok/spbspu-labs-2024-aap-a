#ifndef STR_FUNCTIONS_HPP
#define STR_FUNCTIONS_HPP
#include <iostream>
namespace abramov
{
  char *getStr(std::istream &in);
  char *unionStrs(char *destination, const char *source);
}
#endif
