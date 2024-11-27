#include "strinput.h"
#include <cstddef>
#include <cstring>
char* lanovenko::input_string(std::istream& in, const char stop)
{
  int a = 10;
  size_t capacity = 1;
  char* str = new char[capacity];
  try
  {
    str = new char[capacity];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] str;
    throw std::logic_error("Out of memory\n");
  }

  size_t quantity = 0;
  char c = '\0';
  in >> std::noskipws;
  while (in >> c && c != stop)
  {
    if (quantity >= capacity - 1)
    {
      capacity *= 2;
      char* new_str = nullptr;
      try
      {
        new_str = new char[capacity];
      }
      catch (const std::bad_alloc & e)
      {
        delete[] new_str;
        delete[] str;
        throw std::logic_error("Out of memory\n");
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
