#include "newLetter.h"
#include <cstring>

void cherkasov::newLetter(const char* array, char* result, char oldChar, char newChar)
{
  if (!array || !result)
  {
    return;
  }
  while (*array)
  {
    *result++ = (*array == oldChar) ? newChar : *array;
    ++array;
  }
    *result = '\0';
}
