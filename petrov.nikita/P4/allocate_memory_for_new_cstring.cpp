#include "making_new_cstring.hpp"
#include <cstddef>
#include <exception>

char * petrov::allocateMemoryForNewCString(const size_t capacity)
{
  char * new_cstring = nullptr;
  new_cstring = new char[capacity + 1];
  return new_cstring;
}
