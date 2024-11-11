#include "rep_sym.hpp"
#include <iostream>

std::istream &sveshnikov::read_str(std::istream &in, char *str, size_t len)
{
  std::size_t size = 0;
  char c = '\0';
  while ((std::cin >> c) && (c != '\n'))
  {
    if (size == len)
    {
      memory_alloc(str, len);
    }
    str[size++] = c;
  }
}
