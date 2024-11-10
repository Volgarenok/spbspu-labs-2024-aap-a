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

char *abramov::unionStrs(char *destination, const char *source)
{
  char str[32768] = "\0";
  size_t i = 0;
  size_t k = 0;
  while (destination[i] != '\0' && source[i] != '\0')
  {
    str[k++] = destination[i];
    str[k++] = source[i];
    ++i;
  }
  while (destination[i] != '\0')
  {
    str[k++] = destination[i++];
  }
  while (source[i] != '\0')
  {
    str[k++] = source[i++];
  }
  str[k] = '\0';
  for (size_t j = 0; j < k + 1; ++j)
  {
    destination[j] = str[j];
  }
  return destination;
}
