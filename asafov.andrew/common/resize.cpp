#include "resize.hpp"
#include <exception>

char* asafov::resize(char* string, size_t length, size_t increase)
{
  size_t i = 0;
  char* oldString = string;
  char* newString = nullptr;
  try
  {
    newString = new char[length + increase];
  }
  catch (const std::bad_alloc & e)
  {
    throw e;
  }
  while (i < length)
  {
    newString[i] = oldString[i];
    i++;
  }
  delete[] oldString;
  return newString;
}
