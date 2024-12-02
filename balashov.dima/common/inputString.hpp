#ifndef INPUT_STRING_HPP
#define INPUT_STRING_HPP

#include <cstddef>
#include <iostream>

namespace balashov
{
  char* increaseSizeLine(const char* lineStart, size_t& capacity);
  char* enteringLine(std::istream & in, size_t & capacity);
}
#endif
