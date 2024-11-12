#include "removeVowels.h"
#include "inputOfString.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stdexcept>

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
      std::cerr << "Error: Empty input\n";
      return 1;
    }
  }
  catch (const std::logic_error &e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Error: Memory allocation failed\n";
    return 1;
  }
  removeVowels(inputString);
  std::cout << inputString << "\n";

  free(inputString);
  return 0;
}
