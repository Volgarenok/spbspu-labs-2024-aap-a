#include "newLetter.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <cstdlib>

char* cherkasov::newLetter(char* array, char oldChar, char newChar)
{
  if (!array)
  {
    std::cerr << "Error: Input string is null.\n";
    return nullptr;
  }
  char* result = new (std::nothrow) char[std::strlen(array) + 1];
  if (!result)
  {
    std::cerr << "Error: Faile to allocate memory.\n";
    return nullptr;
  }
  const char* src = array;
  char* dest = result;
  while (*src)
  {
    *dest++ = (*src == oldChar) ? newChar : *src;
    ++src;
  }
  *dest = '\0';
  return result;
}
