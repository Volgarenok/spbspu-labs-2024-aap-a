#include "rep_sym.hpp"
#include <stdexcept>

char *sveshnikov::memory_alloc(char *str, std::size_t *len)
{
  *len += 100;
  char *longer_str = nullptr;
  try
  {
    longer_str = new char[*len];
  }
  catch (const std::bad_alloc &e)
  {
    throw;
  }
  for (std::size_t i = 0; i < *len - 100; i++)
  {
    longer_str[i] = str[i];
  }
  delete[] str;
  return longer_str;
}
