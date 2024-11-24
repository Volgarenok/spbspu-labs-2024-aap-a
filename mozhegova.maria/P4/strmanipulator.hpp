#ifndef STRMANIPULATOR_HPP
#define STRMANIPULATOR_HPP

#include <iostream>

namespace mozhegova
{
  char * inputString(std::istream & in, char stop);
  char * changeSize(const char * nowstr, size_t length);
  char * spcRmv(char * str);
}

#endif
