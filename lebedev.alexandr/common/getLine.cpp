#include "getLine.hpp"

char* lebedev::getLine(std::istream& in, size_t& capacity, char endChar)
{
  char* str = new char[capacity];
  size_t i = 0;
  char ch;

  while (in.get(ch) && ch != endChar)
  {
    if (i >= (capacity - 1))
    {
      capacity *= 2;
      char* newStr = nullptr;
      try
      {
        newStr = new char[capacity];
      }
      catch (const std::bad_alloc& e)
      {
        delete[] str;
        throw;
      }

      for (size_t j = 0; j < i; ++j)
      {
        newStr[j] = str[j];
      }
      delete[] str;
      str = newStr;
    }
    str[i++] = ch;
  }

  str[i] = '\0';
  return str;
}
