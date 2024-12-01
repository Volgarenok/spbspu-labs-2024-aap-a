#include "getString.hpp"
#include <cstddef>

char *abramov::getStr(std::istream &in, size_t &size_of_str)
{
  constexpr size_t max = 20;
  char c = '\0';
  char *str = nullptr;
  try
  {
    str = new char[max + 1];
  }
  catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  size_t new_max = max;
  size_t size = 0;
  std::noskipws(in);
  while (in >> c && c != '\n')
  {
    if (size == new_max)
    {
      new_max *= 2;
      char* new_str = nullptr;
      try
      {
        new_str = new char[new_max + 1];
      }
      catch (const std::bad_alloc &e)
      {
        delete[] str;
        std::skipws(in);
        return nullptr;
      }
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
  size_of_str = size;
  std::skipws(in);
  return str;
}
