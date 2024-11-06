#include "dynamic_string.h"
#include <cctype>
#include <cstddef>
char* alymova::upper_string(char* str)
{
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (std::islower(str[i]))
    {
      str[i] = char(std::toupper(str[i]));
    }
  }
  return str;
}
