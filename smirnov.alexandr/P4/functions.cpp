#include "functions.hpp"
#include <cctype>
#include <cstddef>

char * smirnov::getLine(std::istream & in, char stop)
{
  constexpr size_t max = 10;
  char * str = nullptr;
  try
  {
    str = new char [max + 1];
  }
  catch (const std::bad_alloc & e)
  {
    throw std::logic_error("Out of memory\n");
  }
  size_t size = 0;
  char c = '\0';
  size_t capacity = max;
  in >> std::noskipws;
  while (in >> c && c != stop)
  {
    if (size == capacity)
    {
      capacity *= 2;
      char * new_str = nullptr;
      try
      {
        new_str = new char[capacity + 1];
      }
      catch (const std::bad_alloc & e)
      {
        throw std::logic_error("Out of memory\n");
      }
      for (size_t i = 0; i < capacity; ++i)
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
}
