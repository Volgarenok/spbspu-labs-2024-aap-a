#include "stringManipulator.hpp"
#include <cstddef>

char * inputLine(std::istream & in, char stop)
{
  size_t capacity = 10;
  char * string = nullptr;
  try
  {
    string = new char[capacity] + 1;
  }
  catch (const std::bad_alloc & e)
  {
    delete[] string;
    throw;
  }
  size_t length = 0;
  char ch = '\0';
  in >> std::noskipws;
  while (in >> ch && ch != stop)
  {
    if (length >= capacity)
    {
      capacity *= 2;
      char * newString = nullptr;
      try
      {
        newString = new char[capacity];
      }
      catch(const std::bad_alloc & e)
      {
        delete[] newString;
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
}