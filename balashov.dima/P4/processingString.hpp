#ifndef PROCESSING_STRING_HPP
#define PROCESSING_STRING_HPP

#include<cstddef>

namespace balashov
{
  char* removeSpaces(char* line);
  char* increaseSizeLine(char* lineStart, size_t& capacity);
  char* enteringLine(size_t& capacity);
}

#endif
