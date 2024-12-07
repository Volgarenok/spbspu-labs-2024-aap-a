#include "unionString.hpp"
#include <cstddef>

char * smirnov::getLine(std::istream & in, char stop)
{
  constexpr size_t max = 10;
  char * str = new char[max];
  size_t size = 0;
  char c = '\0';
  size_t capacity = max;
  std::noskipws(in);
  while (in >> c && c != stop)
  {
    if (size == capacity - 1)
    {
      capacity *= 2;
      char * new_str = nullptr;
      try
      {
        new_str = new char[capacity];
      }
      catch (const std::bad_alloc & e)
      {
        delete[] str;
        std::skipws(in);
        throw;
      }
      for (size_t i = 0; i < size; ++i)
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

char * smirnov::uniString(char * result_str, const char * str1, const char * str2)
{
  char * resultPtr = result_str;
  const char * ptr1 = str1;
  const char * ptr2 = str2;
  while (*ptr1 != '\0' && *ptr2 != '\0')
  {
    *resultPtr++ = *ptr1++;
    *resultPtr++ = *ptr2++;
  }
  while (*ptr1 != '\0')
  {
    *resultPtr++ = *ptr1++;
  }
  while (*ptr2 != '\0')
  {
    *resultPtr++ = *ptr2++;
  }
  *resultPtr = '\0';
  return result_str;
}
