#include "removeVowels.h"

bool checkSymbol(char symbol)
{
  const char *list = "aeiouAEIOU";
  while (*list != '\0')
  {
    if (symbol == *list)
    {
      return false;
    }
    ++list;
  }
  return true;
}

char *removeVowels(char *string)
{
  char *result = string;
  for (char *current = string; *current != '\0'; ++current)
  {
    if (checkSymbol(*current))
    {
      *result++ = *current;
    }
  }
  *result = '\0';
  return string;
}
