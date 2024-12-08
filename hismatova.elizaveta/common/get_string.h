#ifndef GET_STRING_H
#define GET_STRING_H
#include <iostream>
#include <cstddef>

namespace hismatova
{
  char* get_line(std::istream& input, size_t& length);
}

#endif
