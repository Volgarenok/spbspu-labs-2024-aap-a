#include "getline.h"
#include <stdexcept>
#include <cstring>
char * bocharov::extend_string(const char * string, std::size_t capacity, std::size_t current_lenght)
{
  if (capacity <= current_lenght)
  {
    throw std::invalid_argument("Capacity must be greater than the current string length");
  }
  char * newString = new char[capacity];
  char * j = newString;
  for (const char * i = string; *i != '\0'; ++i, ++j)
  {
    *j = *i;
  }
  *j = '\0';
  return newString;
}

char * bocharov::getline(std::istream & in, char end_symbol)
{
  std::size_t capacity = 32;
  char * string = new char[capacity];
  std::size_t string_index = 0;
  char symbol = '\0';
  std::noskipws(in);
  while ((in >> symbol) && (symbol != end_symbol))
  {
    if (string_index == capacity - 1)
    {
      string[string_index] = '\0';
      char * extended_string = nullptr;
      try
      {
        extended_string = extend_string(string, capacity *= 2, string_index);
      }
      catch (const std::bad_alloc & e)
      {
        delete[] string;
        std::skipws(in);
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
