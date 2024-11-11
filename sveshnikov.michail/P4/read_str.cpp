#include "rep_sym.hpp"
#include <iostream>

char *sveshnikov::read_str(std::istream &in, char *str, std::size_t *len)
{
  std::size_t size = 0;
  char c = '\0';
  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == *len)
    {
      str = sveshnikov::memory_alloc(str, len);
      if (str == nullptr)
      {
        return nullptr;
      }
    }
    str[size++] = c;
  }
  str[size] = '\0';
  return str;
}
