#include "replaceLetters.hpp"
#include <cstddef>

char * krylov::replaceLetters(char * array, char oldSubstring, char newSubstring)
{
  for (size_t i = 0; array[i] != '\0'; i++)
  {
    if (array[i] == oldSubstring)
    {
      array[i] = newSubstring;
    }
  }
  return array;
}
