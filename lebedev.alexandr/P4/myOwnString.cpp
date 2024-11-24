#include "myOwnString.hpp"

char* lebedev::getLine(std::istream& in, char endChar)
{
  size_t capacity = 10;
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

void lebedev::removeVowels(char* str)
{
  int i = 0, j = 0;
  const char vowels[] = "aeiouAEIOU";

  while (str[i] != '\0')
  {
    bool isVowel = false;
    for (int k = 0; vowels[k] != '\0'; ++k)
    {
      if (str[i] == vowels[k])
      {
        isVowel = true;
        break;
      }
    }

    if (!isVowel)
    {
      str[j++] = str[i];
    }
    i++;
  }

  str[j] = '\0';
}
