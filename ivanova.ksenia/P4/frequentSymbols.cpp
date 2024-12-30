#include "frequentSymbols.h"
#include <cstddef>

namespace
{
  int countFrq(const char * string, int i, int count);
  char * twoFrq(const char * string, int * max, char * maxSym);

  int countFrq(const char * string, int i, int count)
  {
    if (string[i] == '\0')
    {
      return count;
    }
    if (*string == string[i])
    {
      count++;
    }
    return countFrq(string, i + 1, count);
  }

  char * twoFrq(const char * string, int * max, char * maxSym)
  {
    if (*string == '\0')
    {
      return maxSym;
    }

    int count = countFrq(string, 0, 0);

    if (max[0] < count)
    {
      max[1] = max[0];
      maxSym[1] = maxSym[0];

      max[0] = count;
      maxSym[0] = *string;
    }
    else if (count > max[1] && *string != maxSym[0])
    {
      max[1] = count;
      maxSym[1] = *string;
    }
    return twoFrq(string + 1, max, maxSym);
  }
}



char ivanova::frequentSymbol(const char* string)
{
  char dest[3] = {};
  twoFrequentSymbol(string, dest);
  return dest[0];
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

void ivanova::twoFrequentSymbolRec(const char * string, char* dest)
{
  int max[2] = {0, 0};
  char maxSym[2] = {'\0', '\0'};

  twoFrq(string, max, maxSym);

  dest[0] = maxSym[0];
  dest[1] = maxSym[1];
  dest[2] = '\0';
}
