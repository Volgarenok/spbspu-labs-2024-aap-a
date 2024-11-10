#ifndef REP_SYM_HPP
#define REP_SYM_HPP
#include <cstddef>
#include <fstream>

namespace sveshnikov
{
  char * rep_sym_hpp(std::istream &in, char stop);
  std::istream &read_str(std::istream &in, char *matrix);
}
#endif 