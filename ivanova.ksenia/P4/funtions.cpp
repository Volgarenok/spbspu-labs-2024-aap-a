#include "string.h"
#include <cstddef>

char ivanova::frequentSymbol(const char* string)
{
  size_t count = 0;
  size_t max = 0;
  char maxSym = '\0';
  for (size_t i = 0; string[i] != '\0'; i++)
  {
    for (size_t j = 0; string[j] != '\0'; j++)
    {
      if (string[j] == string[i])
      {
        count++;
      }
    }
    if (max < count)
    {
      max = count;
      maxSym = string[i];
    }
  }
  return maxSym;
}

void ivanova::twoFrequentSymbol(const char* string, char* dest)
{
  size_t count = 0;
  size_t max1 = 0, max2 = 0;
  char maxSym1 = '\0';
  char maxSym2 = '\0';
  for (size_t i = 0; string[i] != '\0'; i++)
  {
    for (size_t j = 0; string[j] != '\0'; j++)
    {
      if (string[j] == string[i])
      {
        count++;
      }
    }
    if (max1 < count)
    {
      max2 = max1;
      maxSym2 = maxSym1;

      max1 = count;
      maxSym2 = string[i];
    }
    else if (count > max2 && string[i] != maxSym1)
    {
      max2 = count;
      maxSym2 = string[i];
    }
  }

  dest[0] = maxSym1;
  dest[1] = maxSym2;
  dest[2] = '\0';
}
