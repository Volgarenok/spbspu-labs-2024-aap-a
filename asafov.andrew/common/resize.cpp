#include "resize.hpp"

size_t asafov::ullMin(size_t a, size_t b)
{
  return (a < b) ? (a) : (b);
}

char* asafov::resize(const char* string, size_t oldlength, size_t newlength)
{
  char* newString = new char[newlength + 1];
  for (size_t i = 0; i < ullMin(oldlength, newlength); i++)
  {
    newString[i] = string[i];
  }
  return newString;
}
