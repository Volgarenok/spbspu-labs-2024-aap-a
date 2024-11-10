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
  if (!in)
  {
    throw std::logic_error("Error in create string");
  }
  if ((in>>str[0]) && (str[0] == end))
  {
    throw std::logic_error("Error in create string");
  }
  for (size_t i = 1; (in>>str[i]) && (str[i] != end); i++)
    {
      if ((str[i + 1] != end) && (i + 1) >= (n - 1))
      {
        n = n * 2;
        char* str1 = reinterpret_cast< char* >(malloc(sizeof(char) * n));
        if (str1 == nullptr)
        {
          throw std::logic_error("out of memory");
        }
        for (size_t j = 0; j < (n / 2); j++)
        {
          str1[j] = str[j];
        }
        free(str);
        str = str1;
      }
    }
    std::skipws(in);
    return str;
}
