#ifndef GETLINE_HPP
#define GETLINE_HPP

#include <iostream>

namespace maslevtsov
{
  char* expandString(const char* string, std::size_t capacity);
  char* getline(std::istream& in);
}

#endif
