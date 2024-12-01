#include "rmv_vow.hpp"

char* lebedev::getLine(std::istream& in, size_t& capacity, char endChar)
{
  char* str = new char[capacity];
  size_t i = 0;
  char ch;

  while (in.get(ch) && ch != endChar)
  {
    if (i >= (capacity - 1))
    {
      capacity *= 2;
      char* newStr = nullptr;
      try
      {
        newStr = new char[capacity];
      }
      catch (const std::bad_alloc& e)
      {
        delete[] str;
        throw;
      }

      for (size_t j = 0; j < i; ++j)
      {
        newStr[j] = str[j];
      }
      delete[] str;
      str = newStr;
    }
    str[i++] = ch;
  }

  str[i] = '\0';
  return str;
}

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
