#include "string.hpp"

void lebedev::removeElement(char* str, size_t num)
{
  size_t i = 0;
  while(str[i] != '\0')
  {
    str[i] = str[i + 1];
    ++i;
  }
}

char* lebedev::getLine(std::istream& in, char endChar)
{
  size_t capacity = 10;
  size_t size = 0;
  char* str = new char[capacity];

  char ch = ' ';
  in >> std::noskipws >> ch;
  while (ch != endChar)
  {
    if (size >= capacity - 1)
    {
      capacity *= 2;
      char* newStr = nullptr;
      try
      {
        newStr = new char[capacity];
      }
      catch(std::bad_alloc& e)
      {
        delete[] newStr;
        delete[] str;
        throw;
      }

      size_t i = 0;
      while (str[i] != '\0')
      {
        newStr[i] = str[i];
      }

      delete[] str;
      str = newStr;
    }

    str[size] = ch;
    in >> std::noskipws >> ch;
    size++;
  }

  if (!in)
  {
    return nullptr;
  }

  str[size] = '\0';
  return str;
}

void lebedev::removeVowels(char* str)
{
  size_t i = 0;
  char vowels[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
  while (str[i] != '\0')
  {
    for (size_t j = 0; j < 10; ++j)
    {
      if (str[i] == vowels[j])
      {
        lebedev::removeElement(str, i);
        break;
      }
    }
    ++i;
  }
}
