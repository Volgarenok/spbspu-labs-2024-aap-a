#ifndef REP_SYM_HPP
#define REP_SYM_HPP
#include <cstddef>
#include <fstream>

namespace sveshnikov
{
  char * rep_sym(char *str, char *new_str);
  std::istream &build_str(std::istream &in, char *str);
}
#endif 
