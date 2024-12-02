#include "getLine.hpp"
#include <cstdlib>
#include <iostream>
#include <new>

char* maslovskiy::resizeString(const char *str, size_t strSize, size_t iterSize)
{
  char *resized = static_cast<char*>(malloc(sizeof(char) * (strSize + iterSize + 1)));
  if (resized == nullptr)
  {
    std::cerr << "Error: memory not allocate for string or incorrect parameters\n";
    return nullptr;
  }
  for (size_t i = 0; i < strSize; ++i)
  {
    resized[i] = str[i];
  }
  resized[strSize + iterSize] = '\0';
  return resized;
}

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
        free(str);
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
