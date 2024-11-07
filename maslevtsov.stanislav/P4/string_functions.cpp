#include "string_functions.hpp"

char* maslevtsov::getline(std::istream& in, char* string, std::size_t capacity, char stop)
{
  char symbol = '\0';
  std::size_t stringIndex = 0;

  std::noskipws(in);
  while ((in >> symbol) && (symbol != stop))
  {
    if (stringIndex == capacity)
    {
      string[stringIndex] = '\0';
      maslevtsov::expandString(string, capacity);
    }
    string[stringIndex++] = symbol;
  }
  std::skipws(in);

  return string;
}

void maslevtsov::expandString(char* string, std::size_t& capacity)
{
  capacity *= 2;
  char* newString = new char[capacity];

  for (std::size_t i = 0; string[i] != '\0'; ++i)
  {
    newString[i] = string[i];
  }
  delete[] string;
  string = newString;
}

std::size_t maslevtsov::isSameSymbols(const char *const str1, const char *const str2)
{
  std::size_t counterArray[256] = {0};

  for (std::size_t i = 0; str1[i] != '\0'; ++i)
  {
    ++counterArray[str1[i]];
  }
  for (std::size_t i = 0; str2[i] != '\0'; ++i)
  {
    if (counterArray[str2[i]])
    {
      return 1;
      break;
    }
  }

  return 0;
}
