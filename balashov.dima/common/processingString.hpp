#ifndef PROCESSING_STRING_HPP
#define PROCESSING_STRING_HPP

#include <cstddef>
#include <iostream>

namespace balashov
{
  char* removeSpaces(char* line);
  char* increaseSizeLine(const char* lineStart, size_t& capacity);
  char* enteringLine(std::istream & in, size_t & capacity);
}

#endif
