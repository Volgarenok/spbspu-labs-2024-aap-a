#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace ivanova
{
  char* getLine(std::istream& in);
  char* moreSpace(const char* string, size_t newSize);
  char frequentSymbol(const char* string);
  void twoFrequentSymbol(const char* string, char* dest);
}

#endif
