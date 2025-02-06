#include "resize.hpp"
#include <exception>

char* asafov::resize(const char* string, size_t length, size_t additionallength)
{
  char* newString = nullptr;
  try
  {
    newString = new char[length + additionallength];
  }
  catch (const std::bad_alloc& e)
  {
    throw e;
  }
  for (size_t i = 0; i < length; i++)
  {
    newString[i] = string[i];
  }
  return newString;
}
