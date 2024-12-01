#ifndef GETLINE_HPP
#define GETLINE_HPP
#include <cstddef>
#include <iostream>

namespace sveshnikov
{
  char *read_str(std::istream &in, std::size_t &len);
  char *memory_alloc(const char *str, std::size_t len);
}
#endif
