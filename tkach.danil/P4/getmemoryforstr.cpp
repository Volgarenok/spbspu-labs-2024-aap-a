#include "strfunc.h"
#include <iostream>

int tkach::getMemoryForStr(char*& str, size_t& capacity)
{
  capacity += 1;
  char* newStr = static_cast<char*>(malloc(sizeof(char) * capacity));
  if (newStr == nullptr)
  {
    return 1;
  }
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    newStr[i] = str[i];
  }
  free(str);
  str = newStr;
  return 0;
}
