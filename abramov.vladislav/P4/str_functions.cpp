#include "str_functions.hpp"
#include <cstddef>

char *abramov::getStr(std::istream &in)
{
  constexpr size_t max = 20;
  char c = '\0';
  char *str = new char[max + 1];
  size_t new_max = max;
  size_t size = 0;
  std::noskipws(in);
  while (in >> c && c != '\n')
  {
    if (size == new_max)
    {
      new_max *= 2;
      char *new_str = new char[new_max + 1];
      for (size_t i = 0; i < new_max / 2; ++i)
      {
        new_str[i] = str[i];
      }
      delete[] str;
      str = new_str;
    }
    str[size++] = c;
  }
  str[size] = '\0';
  std::skipws(in);
  return str;
}
