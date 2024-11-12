#include <iostream>

#include "memf.hpp"
#include "string_input.hpp"
#include "string_analysis.hpp"

int main()
{
  constexpr size_t startStringLength = 7;
  char* str = reinterpret_cast<char*>(malloc(startStringLength * sizeof(char)));
  if (!str)
  {
    std::cerr << "failed to allocate string\n";
    return 2;
  }
  str[0] = '\0';
  size_t strLength = startStringLength;

  size_t wPoint = 0;
  while (true)
  {
    size_t wereRead = rychkov::getline(std::cin, str + wPoint, strLength - wPoint);
    if (std::cin.eof() || ((wereRead < strLength - wPoint - 1) && std::cin.good()))
    {
      break;
    }
    if (!std::cin)
    {
      std::cerr << "Failed to read string\n";
      return 1;
    }
    wPoint = strLength - 1;

    size_t newSize = 2 * strLength + 1;
    char* reallocatedStr = rychkov::realloc(str, strLength, newSize);
    if (!reallocatedStr)
    {
      std::cerr << "failed to reallocate string\n";
      free(str);
      return 2;
    }
    str = reallocatedStr;
    strLength = newSize;
  }

  if (*str == '\0')
  {
    std::cerr << "there is no string in stdin\n";
    free(str);
    return 1;
  }

  if (rychkov::findDigitsRepeatsCount(str) != 0)
  {
    std::cout << "entered string has repeated digits\n";
  }
  else
  {
    std::cout << "entered string has no repeated digits\n";
  }
  free(str);
}
