#include "dynamic.h"
#include <cstddef>
#include <cstdlib>
#include <istream>
char* komarova::read(std::istream & input, size_t & size_str, size_t & size_str_now, char end_str)
{
  char * str = reinterpret_cast< char * >(malloc(size_str + 1));
  if (str == nullptr)
  {
    return nullptr;
  }
  str[size_str] = '\0';
  char next = '\0';
  input >> std::noskipws;
  while ((input >> next) && (next != end_str))
  {
    str[size_str_now] = next;
    size_str_now += 1;
    if (size_str_now == size_str)
    {
      size_str = size_str * 10;
      char * str_1 = reinterpret_cast< char* >(malloc(size_str + 1));
      if (str_1 == nullptr)
      {
        size_str = size_str_now;
        free(str);
        return nullptr;
      }
      str_1[size_str] = '\0';
      for (size_t i = 0; str[i] != '\0'; i++)
      {
        str_1[i] = str[i];
      }
      free(str);
      str = str_1;
    }
  }
  str[size_str_now] = '\0';
  input >> std::skipws;
  return str;
}
