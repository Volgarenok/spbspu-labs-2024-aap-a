#ifndef REP_SYM_HPP
#define REP_SYM_HPP
#include <cstddef>
#include <iostream>

namespace sveshnikov
{
  char *rep_sym(const char *str, char *new_str);
  char *read_str(std::istream &in, char *str, std::size_t *len);
  char *memory_alloc(char *str, std::size_t *len);
}
#endif
