#ifndef STR_INPUT_HPP
#define STR_INPUT_HPP
#include <iostream>
#include <cstddef>

namespace dirti
{
  char * new_storage(char * str, size_t & capacity);
  char * str_input(std::istream & input, size_t & capacity);
}

#endif
