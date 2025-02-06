#include "increaseString.hpp"
#include <exception>

char* asafov::increaseString(const char* string, size_t length, size_t additionallength)
{
  char* newString = new char[length + additionallength];
  for (size_t i = 0; i < length; i++)
  {
    newString[i] = string[i];
  }
  return newString;
}
