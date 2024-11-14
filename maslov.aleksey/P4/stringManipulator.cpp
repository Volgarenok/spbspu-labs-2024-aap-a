#include "stringManipulator.hpp"
#include <cstddef>

char * maslov::inputLine(std::istream & in, const char stop)
{
  size_t capacity = 10;
  char * string = new char[capacity];
  size_t length = 0;
  char ch = '\0';
  in >> std::noskipws;
  while (in >> ch && ch != stop)
  {
    if (length == capacity - 1)
    {
      capacity *= 2;
      char * newString = nullptr;
      try
      {
        newString = new char[capacity];
      }
      catch (const std::bad_alloc & e)
      {
        delete[] string;
        throw;
      }
      for (size_t i = 0; i < length; ++i)
      {
        newString[i] = string[i];
      }
      delete[] string;
      string = newString;
    }
    string[length++] = ch;
  }
  string[length] = '\0';
  in >> std::skipws;
  return string;
}

char * maslov::excludeCharacters(char * str1, const char * str2)
{
  char * original = str1;
  char * result = str1;
  while (*str1)
  {
    const char * ptr2 = str2;
    bool found = false;
    while (*ptr2 && !found)
    {
      if (*str1 == *ptr2)
      {
        found = true;
      }
      ptr2++;
    }
    if (!found)
    {
      *result++ = *str1;
    }
    str1++;
  }
  *result = '\0';
  return original;
}
