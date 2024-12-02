#ifndef GET_LINE_HPP
#define GET_LINE_HPP

#include <istream>
#include <cstddef>

namespace maslovskiy
{
  char* inputString(std::istream &in);
  char* resizeString(const char *str, size_t strSize, size_t iterSize);
}

#endif
