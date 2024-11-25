#include "making_new_cstring.hpp"
#include <cstddef>
#include <exception>

char * petrov::allocateMemoryForNewCString(const size_t capacity)
{
  char * new_cstring = nullptr;
  try
  {
    new_cstring = new char[capacity + 1];
  }
  catch (const std::bad_alloc & e)
  {
    throw;
  }
  return new_cstring;
}
