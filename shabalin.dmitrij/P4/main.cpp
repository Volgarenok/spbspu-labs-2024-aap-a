#include <iostream>

char *inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someCharacter = 0;
  size_t index = 0;
  char *initialString = (char *)malloc(sizeOfString * sizeof(char));
  input >> std::noskipws;

  while (input >> someCharacter)
  {
    if (!input)
    {
      free(initialString);
      throw std::logic_error("Input error");
    }
    if (index == sizeOfString - 1)
    {
      try
      {
        sizeOfString *= 2;
        char *intermediateString = (char *)malloc(sizeOfString * sizeof(char));
        for (size_t i = 0; i < index; ++i)
        {
          intermediateString[i] = initialString[i];
        }

        free(initialString);
        initialString = intermediateString;
      }
      catch (std::bad_alloc &e)
      {
        free(initialString);
        throw;
      }
    }
    initialString[index] = someCharacter;
    index++;
  }
  return initialString;
}

int main()
{
  return 0;
}
