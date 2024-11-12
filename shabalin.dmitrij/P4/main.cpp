#include <cstdio>
#include <iostream>

bool checkSymbol(char c)
{
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

char* removeVowels(char *string)
{
  char *begin = string;
  char *result = string;
  while (*string != '\0')
  {
    if (checkSymbol(*string))
    {
      *result = *string;
      ++result;
    }
    ++string;
  }
  *result = '\0';

  return begin;
}

char *inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someCharacter = 0;
  size_t index = 0;
  char *initialString = reinterpret_cast< char* >(malloc(sizeof(char) * sizeOfString));
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
        char *intermediateString = reinterpret_cast< char* >(malloc(sizeof(char) * sizeOfString));
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
  char *inputString = nullptr;
  size_t stringSize = 10;
  try
  {
    inputString = inputOfString(std::cin, stringSize);
    if (inputString[0] == '\0')
    {
      free(inputString);
      std::cerr << "Error" << "\n";
      return 1;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  removeVowels(inputString);
  std::cout << inputString << "\n";
  free(inputString);
  return 0;
}
