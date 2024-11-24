#ifndef SEARCH_REPEATS_HPP
#define SEARCH_REPEATS_HPP
#include <cstddef>
#include <iostream>

namespace sveshnikov
{
  char *rep_sym(const char *str, char *new_str);
  char *read_str(std::istream &in);
  char *memory_alloc(char *str, std::size_t len);
}
#endif
