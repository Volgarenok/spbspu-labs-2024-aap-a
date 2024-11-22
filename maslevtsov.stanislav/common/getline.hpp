#ifndef GETLINE_HPP
#define GETLINE_HPP

#include <iostream>

namespace maslevtsov
{
  char* maslevtsov::expandString(const char* string, std::size_t capacity);
  char* maslevtsov::getline(std::istream& in);
}

#endif