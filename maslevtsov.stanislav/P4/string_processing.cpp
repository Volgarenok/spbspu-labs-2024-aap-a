#include "string_processing.hpp"
#include <stdexcept>

char* maslevtsov::expandString(char* string, std::size_t& capacity)
{
  capacity *= 2;
  char* newString = new char[capacity];

  for (std::size_t i = 0; string[i] != '\0'; ++i)
  {
    newString[i] = string[i];
  }
  delete[] string;

  return newString;
}

char* maslevtsov::getline(std::istream& in)
{
  std::size_t stringCapacity = 4;
  char* string = nullptr;
  try
  {
    string = new char[stringCapacity];
  }
  catch (const std::bad_alloc& e)
  {
    return nullptr;
  }
  std::size_t stringIndex = 0;
  char symbol = '\0';

  std::noskipws(in);
  while ((in >> symbol) && (!in.eof()))
  {
    if (stringIndex == stringCapacity - 1)
    {
      string[stringIndex] = '\0';
      try
      {
        string = maslevtsov::expandString(string, stringCapacity);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] string;
        return nullptr;
      }
    }
    string[stringIndex++] = symbol;
  }
  std::skipws(in);
  string[stringIndex] = '\0';

  return string;
}

std::size_t maslevtsov::isSameSymbols(const char* const str1, const char* const str2)
{
  for (std::size_t i = 0; str1[i] != '\0'; ++i)
  {
    for (std::size_t j = 0; str2[j] != '\0'; ++j)
    {
      if (str1[i] == str2[j])
      {
        return 1;
        break;
      }
    }
  }

  return 0;
}
