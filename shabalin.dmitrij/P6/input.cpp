#include "input.hpp"

char *shabalin::inputOfString(std::istream &input, char end)
{
  size_t sizeOfString = 123;
  size_t index = 0;
  char *initialString = reinterpret_cast< char* >(malloc(sizeOfString));

  if (!initialString)
  {
    return initialString;
  }

  input >> std::noskipws;
  char someCharacter = 0;
  if (someCharacter == end)
  {
    return initialString;
  }

  while ((input >> someCharacter) && (someCharacter != end))
  {
    if (index == sizeOfString - 1)
    {
      sizeOfString *= 2;
      char *intermediateString = reinterpret_cast< char* >(malloc(sizeOfString));
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
