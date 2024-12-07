#include "newLetter.h"
#include <cstddef>
#include <cstring>
#include <iostream>

void cherkasov::newLetter(char* result, const char* array, char oldChar, char newChar)
{
  if (!array || !result)
  {
    std::cerr << "Error: invalid input pointers.\n";
    return;
  }
  const char* src = array;
  char* dest = result;
  while (*src)
  {
    *dest++ = (*src == oldChar) ? newChar : *src;
    ++src;
  }
    *dest = '\0';
}
