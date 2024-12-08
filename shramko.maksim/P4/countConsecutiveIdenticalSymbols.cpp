#include "countConsecutiveIdenticalSymbols.hpp"
#include <cstdlib>

size_t shramko::countConsecutiveIdenticalSymbols(const char* str)
{
  if (str == nullptr)
  {
    return 0;
  }

  size_t result = 0;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (str[i] == str[i + 1])
    {
      ++result;
    }
  }
  return result;
}
