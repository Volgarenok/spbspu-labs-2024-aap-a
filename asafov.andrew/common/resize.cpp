#include "resize.hpp"
#include <algorithm>

char* asafov::resize(const char* string, size_t oldlength, size_t newlength)
{
  char* newString = new char[newlength];
  for (size_t i = 0; i < std::min(newlength, oldlength); i++)
  {
    newString[i] = string[i];
  }
  return newString;
}
