#ifndef INPUTSTRING_HPP
#define INPUTSTRING_HPP

#include <iostream>

namespace sharifullina
{
  char * inputstring(std::istream & in, char stop);
  char * inputStringRecursive(std::istream& in, char stop);
}
#endif
