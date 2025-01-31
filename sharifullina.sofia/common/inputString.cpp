#include "inputString.hpp"

char * sharifullina::inputstring(std::istream & in, char stop)
{
  size_t capacity = 10;
  char * str = new char[capacity];
  size_t size = 0;
  char ch = '\0';
  std::noskipws(in);
  while ((in >> ch) && (ch != stop))
  {
    if (capacity == size)
    {
      capacity = capacity * 2;
      char * newstr = nullptr;
      try
      {
        newstr = new char[capacity];
      }
      catch (const std::bad_alloc & e)
      {
        delete[] str;
        std::skipws(in);
        throw;
      }
      for (size_t i = 0; i < size; ++i)
      {
        newstr[i] = str[i];
      }
      delete[] str;
      str = newstr;
    }
    str[size++] = ch;
  }
  str[size] = '\0';
  in >> std::skipws;
  return str;
}

namespace
{
  char * fillStringRecursive(std::istream& in, char stop, size_t index)
  {
    char ch = '\0';
    in >> std::noskipws >> ch;
    if (!in || ch == stop)
    {
      char * str = new char[index + 1];
      str[index] = '\0';
      return str;
    }
    char * str = fillStringRecursive(in, stop, index + 1);
    str[index] = ch;
    return str;
  }
}
char * sharifullina::inputStringRecursive(std::istream& in, char stop)
{
  return fillStringRecursive(in, stop, 0);
}
