#include "getline.hpp"
#include <stdexcept>

char* maslevtsov::expandString(const char* string, std::size_t capacity)
{
  char* newString = new char[capacity];
  char* j = newString;
  for (const char* i = string; *i != '\0'; ++i, ++j)
  {
    *j = *i;
  }

  return newString;
}

char* maslevtsov::getline(std::istream& in)
{
  std::size_t stringCapacity = 32;
  char* string = new char[stringCapacity];
  std::size_t stringIndex = 0;
  char symbol = '\0';

  std::noskipws(in);
  while ((in >> symbol) && (symbol != '\n'))
  {
    if (stringIndex == stringCapacity - 1)
    {
      string[stringIndex] = '\0';
      char* expandedString = nullptr;
      try
      {
        expandedString = expandString(string, stringCapacity *= 2);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] string;
        throw;
      }
      delete[] string;
      string = expandedString;
    }
    string[stringIndex++] = symbol;
  }
  std::skipws(in);
  string[stringIndex] = '\0';

  return string;
}
