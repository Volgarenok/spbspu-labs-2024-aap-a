#include "strfunc.h"
#include <iostream>

char* tkach::getMemoryForStr(const char* str, size_t& capacity)
{
  capacity *= 2;
  char* newStr = static_cast< char* >(malloc(sizeof(char) * capacity));
  if (newStr == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    newStr[i] = str[i];
  }
  return newStr;
}
