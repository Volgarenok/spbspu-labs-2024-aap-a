#include "rep_sym.hpp"
#include <iostream>

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
    std::cerr << e.what() << '\n';
    delete[] str;
    return nullptr;
  }
  for (std::size_t i = 0; i < *len - 100; i++)
  {
    longer_str[i] = str[i];
  }
  delete[] str;
  return longer_str;
}
