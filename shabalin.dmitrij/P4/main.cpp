#include <cstdio>
#include <iostream>

bool checkSymbol(char c)
{
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

void removeVowels(char *in, char *dest)
{
  for (auto i = in; *i != '\0'; i++)
  {
    if (!checkSymbol(*i))
    {
      *dest = *i;
      dest++;
    }
  }
  *dest = '\0';
}

char *inputOfString(std::istream &input, size_t &sizeOfString)
{
  char someCharacter = 0;
  size_t index = 0;
  char *initialString = new char[sizeOfString];
  input >> std::noskipws;

  while (input >> someCharacter)
  {
    if (!input)
    {
      delete[] initialString;
      throw std::logic_error("Input error");
    }
    if (index == sizeOfString - 1)
    {
      try
      {
        sizeOfString *= 2;
        char *intermediateString = new char[sizeOfString];
        for (size_t i = 0; i < index; ++i)
        {
          intermediateString[i] = initialString[i];
        }

        delete[] initialString;
        initialString = intermediateString;
      }
      catch (std::bad_alloc &e)
      {
        delete[] initialString;
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
  char *result = nullptr;
  try
  {
    inputString = inputOfString(std::cin, stringSize);
    if (inputString[0] == '\0')
    {
      delete[] inputString;
      std::cerr << "Error" << "\n";
      return 1;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  try
  {
    result = new char[stringSize];
  }
  catch (const std::bad_alloc &e)
  {
    delete[] inputString;
    delete[] result;
    std::cerr << e.what() << "\n";
    return 1;
  }
  removeVowels(inputString, result);
  std::cout << result << "\n";
  delete[] inputString;
  return 0;
}
