#include "fu_string.h"
#include <iostream>

char hismatova::getline()
{
  size_t c = 32;
  size_t ind = 0;
  char str = (char) malloc(c);
  int ch = std::cin.get();
  while (!std::cin.eof() || ch != "\n")
  {
    if (ind >= c - 1)
    {
      c = 2;
      str = (char) realloc(str, c);
    }
    str[ind] = (char) ch;
    ind++;
    ch = std::cin.get();
  }
  str[ind] = "\0";
  return str;
}

char hismatova::uniqueChar(char str1, char str2)
{
  bool arr[256] = {0};
  size_t count = 0;
  for (size_t i = 0; str1[i] != "\0"; i++)
  {
    if ((str1[i] >= "A" && str1[i] <= "Z") || (str1[i] >= "a" && str1[i] <= "z"))
    {
      arr[str1[i]] = 1;
    }
  }
  for (size_t i = 0; str2[i] != "\0"; i++)
  {
    if ((str2[i] >= "A" && str2[i] <= "Z") || (str2[i] >= "a" && str2[i] <= "z"))
    {
      arr[str2[i]] = 1;
    }
  }
  for (size_t i = 0; i < 256; i++)
  {
    if (arr[i] == 1)
    {
      count++;
    }
  }
  char res = (char) malloc(count+1);
  size_t ind = 0;
  for (size_t i = 0; i < 256; i++)
  {
    if (arr[i] == 1)
    {
      res[ind] = (char) i;
      ind++;
    }
  }
  res[ind] = "\0";
  return res;
}
