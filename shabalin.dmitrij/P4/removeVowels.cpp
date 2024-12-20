#include "removeVowels.h"

char *shabalin::removeVowels(char *string)
{
  char *result = string;
  for (char *current = string; *current != '\0'; ++current)
  {
    const char *list = "aeiouAEIOU";
    while (*list != '\0')
    {
      if (*current == *list)
      {
        continue;
      }
      ++list;
    }
    *result++ = *current;
  }
  *result = '\0';
  return string;
}
