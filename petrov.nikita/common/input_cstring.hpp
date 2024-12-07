#ifndef INPUT_CSTRING_HPP
#define INPUT_CSTRING_HPP

#include <iostream>
#include <exception>

namespace petrov
{
  char * inputCString(std::istream & in, size_t & capacity);
}
#endif
