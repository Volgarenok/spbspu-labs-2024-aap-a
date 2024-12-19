#include "input_string.hpp"
char* lanovenko::inputStr(std::istream& in)
{
  size_t capacity = 10;
  char* str = new char[capacity];
  size_t quantity = 0;
  char c = '\0';
  in >> std::noskipws;
  while (in >> c && c != '\n')
  {
    if (quantity >= capacity - 1)
    {
      capacity *= 2;
      char* new_str = nullptr;
      try
      {
        new_str = new char[capacity];
      }
      catch (const std::bad_alloc& e)
      {
        in >> std:skipws;
        delete[] str;
        throw;
      }
      for (size_t i = 0; i < quantity; i++)
      {
        new_str[i] = str[i];
      }
      delete[] str;
      str = new_str;
    }
    str[quantity++] = c;
  }
  str[quantity] = '\0';
  in >> std::skipws;
  return str;
}

