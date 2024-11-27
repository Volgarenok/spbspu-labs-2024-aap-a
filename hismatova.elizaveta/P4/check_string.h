#ifndef CHECK_STRING_H
#define CHECK_STRING_H
#include <iostream>
#include <cstddef>

namespace hismatova
{
  int getLine(std::istream& input, char** str);
  char* uniqueChar(const char* str1, const char* str2);
}

#endif
