#include "resize.hpp"
#include <exception>

char* asafov::resize(const char* string, size_t length)
{
  char* newString = new char[length + 1];
  for (size_t i = 0; i < length; i++)
  {
    newString[i] = string[i];
  }
  return newString;
}
