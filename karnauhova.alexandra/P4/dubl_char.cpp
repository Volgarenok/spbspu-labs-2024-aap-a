#include "dubl_char.hpp"
#include <cstddef>
int karnauhova::dubl_char(const char* str)
{
  char k = 0;
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    k = str[i];
    for (size_t j = (i + 1); str[j] != '\0'; j++)
    {
      if (str[j] == k)
      {
        return 1;
      }
    }
  }
  return 0;
}
