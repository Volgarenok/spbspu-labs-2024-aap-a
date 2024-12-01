#ifndef CHECK_STRING_H
#define CHECK_STRING_H
#include <iostream>
#include <cstddef>

namespace hismatova
{
  char* getLine(std::istream& input);
  void uniqueChar(const char* str1, const char* str2, char* result);
}

#endif
