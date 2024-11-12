#include "strfunc.h"
#include <iostream>

char* tkach::getMemoryForStr(char* str, size_t& capacity)
{
  capacity += 1;
  char* newStr = nullptr;
  newStr = static_cast<char*>(malloc(sizeof(char) * capacity));
  if (newStr == nullptr)
  {
    throw;
  }
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    newStr[i] = str[i];
  }
  free(str);
  return newStr;
}
