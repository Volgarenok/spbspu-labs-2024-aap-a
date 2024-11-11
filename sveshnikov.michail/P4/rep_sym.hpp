#ifndef REP_SYM_HPP
#define REP_SYM_HPP
#include <cstddef>
#include <fstream>

namespace sveshnikov
{
  char * rep_sym(const char *str, char *new_str);
  std::istream &build_str(std::istream &in, char *str, size_t len);
  char * memory_alloc(char *str, size_t len);
}
#endif 
