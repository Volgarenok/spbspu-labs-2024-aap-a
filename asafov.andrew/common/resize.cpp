#include "resize.hpp"
#include <exception>

char* asafov::resize(const char* string, size_t oldlength, size_t newlength)
{
  char* newString = new char[newlength + 1];
  for (size_t i = 0; i < oldlength; i++)
  {
    newString[i] = string[i];
  }
  return newString;
}
