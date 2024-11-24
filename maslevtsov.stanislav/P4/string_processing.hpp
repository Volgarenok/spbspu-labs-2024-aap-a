#ifndef STRING_PROCESSING_HPP
#define STRING_PROCESSING_HPP

#include <iostream>

namespace maslevtsov
{
  char* getline(std::istream& in);
  char* expandString(const char* string, std::size_t capacity);
  int isSameSymbols(const char* str1, const char* str2);
}

#endif
