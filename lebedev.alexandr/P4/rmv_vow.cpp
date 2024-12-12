#include "rmv_vow.hpp"

bool lebedev::isVowel(const char c)
{
  const char vowels[] = "aeiouAEIOU";
  for (size_t i = 0; vowels[i] != '\0'; ++i)
  {
    if (c == vowels[i])
    {
      return true;
    }
  }
  return false;
}

void lebedev::removeVowels(const char* str, char* str_without_vowels)
{
  char* pointer2 = str_without_vowels;
  for (const char* pointer1 = str; (*pointer1) != '\0'; pointer1++)
  {
    if (!isVowel(*pointer1))
    {
      *(pointer2++) = *pointer1;
    }
  }
  *pointer2 = '\0';
}
