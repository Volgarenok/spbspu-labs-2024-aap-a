#include "processingString.hpp"
#include <cmath>

char* balashov::removeSpaces(char * line)
{
  char* lineWithoutSpaces = line;
  char* pointerToChange = line;
  bool spaceLastSymbol = false;
  bool isFirstSymbol = true;
  while (*line != '\0')
  {
    if (*line != ' ')
    {
      *pointerToChange++ = *line;
      spaceLastSymbol = false;
      isFirstSymbol = false;
    }
    else if (!spaceLastSymbol && !isFirstSymbol)
    {
      *pointerToChange++ = ' ';
      spaceLastSymbol = true;
    }
    line++;
  }
  if (spaceLastSymbol && !isFirstSymbol)
  {
    pointerToChange--;
  }
  *pointerToChange = '\0';
  return lineWithoutSpaces;
}
