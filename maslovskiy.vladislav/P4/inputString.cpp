#include "inputString.hpp"
#include "resizeString.hpp"
#include <cstdlib>
#include <iostream>

char* maslovskiy::inputString(std::istream &in)
{
  const size_t iterSize = 10;
  size_t strSize = iterSize;
  char *str = static_cast<char*>(malloc(sizeof(char) * iterSize));
  if (str == nullptr)
  {
    std::cerr << "Error: memory not allocated for string or incorrect parameters\n";
    return nullptr;
  }
  char ch = 0;
  size_t i = 0;
  in >> std::noskipws;
  while (in >> ch)
  {
    if (ch == '\n')
    {
      break;
    }
    if (i == strSize)
    {
      char *temp = resizeString(str, strSize, iterSize);
      if (temp == nullptr)
      {
        std::cerr << "Error: memory not allocated for string or incorrect parameters\n";
        return nullptr;
      }
      strSize += iterSize;
      free(str);
      str = temp;
    }
    str[i] = ch;
    ++i;
  }
  str[i] = '\0';
  in >> std::skipws;
  return str;
}
