#include "input_string.hpp"
#include <stdexcept>
#include <fstream>
#include <cstddef>
char* karnauhova::input_string(std::istream& in, char end)
{
  size_t n = 20;
  char* str = nullptr;
  str = reinterpret_cast< char* >(malloc(sizeof(char) * n));
  if (str == nullptr)
  {
    throw std::logic_error("out of memory");
  }
  std::noskipws(in);
  char x = 0;
  in >> x;
  if (x == end)
  {
    free(str)
    throw std::logic_error("Error in create string");
  }
  str[0] = x;
  size_t i = 1;
  while ((in >> x) && (x != end))
    {
      if (i >= (n))
      {
        n = n * 2;
        char* str1 = reinterpret_cast< char* >(malloc(sizeof(char) * n));
        if (str1 == nullptr)
        {
          free(str);
          throw std::logic_error("out of memory");
        }
        for (size_t j = 0; j < (n / 2); j++)
        {
          str1[j] = str[j];
        }
        free(str);
        str = str1;
      }
      str[i] = x;
      i++;
    }
    std::skipws(in);
    return str;
}
