#ifndef FINDMIN_HPP
#define FINDMIN_HPP
#include <iostream>
#include <cstddef>

namespace dirti
{
  void countSym(const char * str, char * symbols, size_t * sym_num, size_t & sym);
  char findMin(const char * str);
}

#endif
