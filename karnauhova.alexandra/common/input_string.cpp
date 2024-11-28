#include "input_string.hpp"
#include <stdexcept>
#include <fstream>
#include <cstddef>
char* karnauhova::input_string(std::istream& in, char end)
{
  size_t n = 20;
  char* str = reinterpret_cast< char* >(malloc(sizeof(char) * n));
  if (str == nullptr)
  {
    return str;
  }
  std::noskipws(in);
  char x = 0;
  in >> x;
  if (x == end)
  {
    return str;
  }
  str[0] = x;
  size_t i = 1;
  while ((in >> x) && (x != end))
  {
    if ((i + 1) >= n)
    {
      n = n * 2;
      char* str1 = reinterpret_cast< char* >(malloc(sizeof(char) * n));
      if (str1 == nullptr)
      {
        free(str);
        return str1;
      }
      for (size_t j = 0; j < (n / 2); j++)
      {
        str1[j] = str[j];
      }
      free(str);
      str = str1;
    }
    str[i] = x;
    str[i + 1] = '\0';
    i++;
  }
  std::skipws(in);
  return str;
}
