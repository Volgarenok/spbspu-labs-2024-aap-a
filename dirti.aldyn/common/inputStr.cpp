#include "inputStr.hpp"

namespace
{
  char * allocMemory(const char * str, size_t & capacity)
  {
    capacity += 1;
    char * str2 = reinterpret_cast< char * >(malloc(sizeof(char) * capacity));
    if (str2 == nullptr)
    {
      return nullptr;
    }
    for (size_t i = 0; i < (capacity - 1); ++i)
    {
      str2[i] = str[i];
    }
    return str2;
  }
}

char * dirti::inputStr(std::istream & input, size_t & capacity)
{
  char c = '\0';
  size_t size = 0;
  char * str = reinterpret_cast< char * >(malloc(sizeof(char) * capacity));
  if (str == nullptr)
  {
    return nullptr;
  }
  std::noskipws(input);
  while ((input >> c) && (c != '\n'))
  {
    char * str2 = allocMemory(str, capacity);
    free(str);
    if (str2 == nullptr)
    {
      std::skipws(input);
      return nullptr;
    }
    str = str2;
    str[size++] = c;
  }
  if (size == 0)
  {
    free(str);
    std::skipws(input);
    return nullptr;
  }
  str[size] = '\0';
  std::skipws(input);
  return str;
}
