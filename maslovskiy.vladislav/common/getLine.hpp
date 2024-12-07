#ifndef GET_LINE_HPP
#define GET_LINE_HPP

#include <istream>
#include <cstddef>

namespace maslovskiy
{
  char* getLine(std::istream& input, size_t &capacity);
  char* reallocate(char* line, size_t &capacity, size_t factor, size_t addSizeOptional = 0);
}

#endif
