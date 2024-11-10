#include "dubl_char.hpp"
#include <cstddef>
int karnauhova::dubl_char(char* str)
{
  int asci[127] = {0};
  for (size_t i = 0; str[i] != '\0'; i++)
  {
    if (asci[int(str[i])] == 1)
    {
      return 1;
    }
    asci[int(str[i])] += 1;
  }
  return 0;
}
