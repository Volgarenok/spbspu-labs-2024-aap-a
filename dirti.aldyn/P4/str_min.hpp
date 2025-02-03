#ifndef STR_MIN_HPP
#define STR_MIN_HPP
#include <iostream>
#include <cstddef>

namespace dirti
{
  void sym_count(const char * str, char * sym_name, char * sym_num, size_t size, size_t & sym);
  char str_min(const char * str, size_t size);
}

#endif
