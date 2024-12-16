#include "functions.h"
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
  char maxSym1 = frequentSymbol(string);
  char strWithoutSym1[300] = {0};
  size_t k = 0;
  for (size_t i = 0; string[i] != '\0'; i++)
  {
    if (string[i] != maxSym1)
    {
      strWithoutSym1[k++] = string[i];
    }
  }
  strWithoutSym1[k] = '\0';
  char maxSym2 = frequentSymbol(strWithoutSym1);
  dest[0] = maxSym1;
  dest[1] = maxSym2;
  dest[2] = '\0';
}
