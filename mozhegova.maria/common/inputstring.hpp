#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <iostream>

namespace mozhegova
{
  char * inputString(std::istream & in, char stop);
  char * changeSize(char * nowstr, size_t length);
}

#endif
