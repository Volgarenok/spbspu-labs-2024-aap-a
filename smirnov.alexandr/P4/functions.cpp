#include "functions.hpp"
#include <cstddef>
#include <cstring>

char * smirnov::getLine(std::istream & in, char stop)
{
  constexpr size_t max = 10;
  char * str = new char[max + 1];
  size_t size = 0;
  char c = '\0';
  size_t capacity = max;
  std::noskipws(in);
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
        delete[] str;
        throw std::logic_error("Out of memory\n");
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
  delete[] str;
}

char * smirnov::uniString(const char * str1, const char * str2)
{
  size_t length1 = strlen(str1);
  size_t length2 = strlen(str2);
  size_t maxLength = length1 + length2;
  char * result = new char[maxLength + 1];
  size_t index = 0;
  for (size_t i = 0; i < std::max(length1, length2); ++i)
  {
    if (i < length1)
    {
      result[index++] = str1[i];
    }
    if (i < length2)
    {
      result[index++] = str2[i];
    }
  }
  result[index] = '\0';
  return result;
}
