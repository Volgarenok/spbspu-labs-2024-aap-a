#include <iostream>

#include "memf.hpp"
#include "string_input.hpp"
#include "string_analysis.hpp"

int main()
{
  constexpr size_t startStringLength = 7;
  char* str = reinterpret_cast< char* >(malloc(startStringLength * sizeof(char)));
  if (!str)
  {
    std::cerr << "failed to allocate string\n";
    return 1;
  }
  str[0] = '\0';
  size_t strLength = startStringLength;

  size_t wPoint = 0;
  size_t wereRead = 0;
  while (rychkov::getline(std::cin, str + wPoint, strLength - wPoint, '\n', &wereRead)
      && (wereRead == strLength - wPoint - 1))
  {
    wPoint = strLength - 1;

    size_t newSize = 2 * strLength + 1;
    char* reallocatedStr = rychkov::realloc(str, strLength, newSize);
    if (!reallocatedStr)
    {
      std::cerr << "failed to reallocate string\n";
      free(str);
      return 1;
    }
    str = reallocatedStr;
    strLength = newSize;
  }
  if (std::cin.fail())
  {
    std::cerr << "Failed to read string\n";
    free(str);
    return 1;
  }
  if (*str == '\0')
  {
    std::cerr << "there is no string in stdin\n";
    free(str);
    return 1;
  }

  std::cout << (rychkov::findDigitsRepeatsCount(str) != 0 ? 1 : 0) << '\n';
  free(str);
}
