#include "inputOfString.h"

char *shabalin::inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someCharacter = 0;
  size_t index = 0;
  char *initialString = reinterpret_cast<char *>(malloc(sizeof(char) * sizeOfString));

  if (!initialString)
  {
    throw std::bad_alloc();
  }

  input >> std::noskipws;

  while (input >> someCharacter)
  {
    if (index == sizeOfString - 1)
    {
      sizeOfString *= 2;
      char *intermediateString = reinterpret_cast<char *>(realloc(initialString, sizeof(char) * sizeOfString));
      if (!intermediateString)
      {
        free(initialString);
        throw std::bad_alloc();
      }
      initialString = intermediateString;
    }
    initialString[index++] = someCharacter;
  }
  initialString[index] = '\0';
  return initialString;
}
