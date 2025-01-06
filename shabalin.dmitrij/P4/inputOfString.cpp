#include "inputOfString.h"

char *shabalin::inputOfString(std::istream &input, char end)
{
  size_t sizeOfString = 123;
  size_t index = 1;

  char *initialString = reinterpret_cast< char* >(malloc(sizeOfString));

  if (!initialString)
  {
    return initialString;
  }

  std::noskipws(input);
  char someCharacter = 0;
  input >> someCharacter;
  if (someCharacter == end)
  {
    return initialString;
  }
  initialString[0] = someCharacter;
  while ((input >> someCharacter) && (someCharacter != end))
  {
    if (index >= sizeOfString)
    {
      sizeOfString *= 2;
      char *intermediateString = reinterpret_cast< char* >(malloc(sizeOfString));
      if (intermediateString == nullptr)
      {
        free(initialString);
        return intermediateString;
      }
      for (size_t j = 0; j < (sizeOfString / 2); ++j)
      {
        intermediateString[j] = initialString[j];
      }
      free(initialString);
      initialString = intermediateString;
    }
    initialString[index++] = someCharacter;
  }
  initialString[index] = '\0';
  return initialString;
}
