#include "newLetter.h"
#include <cstddef>
#include <cstring>
#include <new>

char* cherkasov::newLetter(const char* array, char oldChar, char newChar)
{
  if (!array)
  {
    return nullptr;
  }
  size_t length = std::strlen(array);
  char* result = new (std::nothrow) char[length + 1];
  if (!result)
  {
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
