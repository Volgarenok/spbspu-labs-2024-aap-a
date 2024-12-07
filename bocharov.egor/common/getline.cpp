#include "getline.h"
#include <stdexcept>
char * bocharov::extend_the_string(const char * string, std::size_t capacity)
{
  char * newString = new char[capacity];
  char * j = newString;
  for (const char * i = string; *i != '\0'; ++i, ++j)
  {
    *j = *i;
  }

  return newString;
}

char * bocharov::getline(std::istream & in)
{
  std::size_t capacity = 32;
  char * string = new char[capacity];
  std::size_t string_index = 0;
  char symbol = '\0';

  std::noskipws(in);
  while ((in >> symbol) && (symbol != '\n'))
  {
    if (string_index == capacity - 1)
    {
      string[string_index] = '\0';
      char * extended_string = nullptr;
      try
      {
        extended_string = extend_the_string(string, stringCapacity *= 2);
      }
      catch (const std::bad_alloc & e)
      {
        delete[] string;
        throw;
      }
      delete[] string;
      string = extended_string;
    }
    string[string_index++] = symbol;
  }
  std::skipws(in);
  string[string_index] = '\0';

  return string;
}
