#include "removevowels.h"

bool tkach::isVowel(const char* str)
{
  constexpr char str3[] = "eyuioaEYUIOA";
  for(size_t i = 0; str3[i] != '\0'; ++i)
  {
    if (*str == str3[i])
    {
      return true;
    }
  }
  return false;
}

size_t tkach::getStrWithRemovedVowels(const char* str, char* str2)
{
  char* str2pointer = str2;
  size_t amountofdeleted = 0;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (!isVowel((str + i)))
    {
      *(str2pointer++) = str[i];
    }
  }
  *(str2pointer) = '\0';
  return amountofdeleted;
}
