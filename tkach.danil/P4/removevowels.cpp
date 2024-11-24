#include "removevowels.h"

bool tkach::isVowel(const char* str)
{
  constexpr char str_of_all_vowels[] = "eyuioaEYUIOA";
  for (const char* str_pointer = str_of_all_vowels; (*str_pointer) != '\0'; str_pointer++)
  {
    if (*str == *str_pointer)
    {
      return true;
    }
  }
  return false;
}

size_t tkach::getStrWithRemovedVowels(const char* str, char* str2)
{
  char* str_pointer2 = str2;
  size_t amount_of_deleted = 0;
  for (const char* str_pointer1 = str; (*str_pointer1) != '\0'; str_pointer1++)
  {
    if (!isVowel(str_pointer1))
    {
      *(str_pointer2++) = *str_pointer1;
    }
    else
    {
      amount_of_deleted++;
    }
  }
  *(str_pointer2) = '\0';
  return amount_of_deleted;
}
