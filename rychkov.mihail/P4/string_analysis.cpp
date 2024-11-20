#include "string_analysis.hpp"

#include <cctype>

size_t rychkov::findDigitsRepeatsCount(const char* str)
{
  size_t digitsRepeats[10]{0};
  while (*str != '\0')
  {
    if (std::isdigit(*str))
    {
      digitsRepeats[*str - '0']++;
    }
    str++;
  }
  size_t result = 0;
  for (size_t i = 0; i < 10; i++)
  {
    result += (digitsRepeats[i] != 0 ? digitsRepeats[i] - 1 : 0);
  }
  return result;
}
