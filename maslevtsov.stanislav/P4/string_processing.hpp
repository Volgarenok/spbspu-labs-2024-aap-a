#ifndef STRING_PROCESSING_HPP
#define STRING_PROCESSING_HPP

#include <iostream>

namespace maslevtsov
{
  char* getline(std::istream& in);
  char* expandString(char* string, std::size_t& capacity);
  std::size_t isSameSymbols(const char* const str1, const char* const str2);
}

#endif
