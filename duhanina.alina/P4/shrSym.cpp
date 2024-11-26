#include "shrSym.h"
#include <cctype>
#include <cstddef>

void duhanina::shrSym(const char* str, char* missing)
{
  size_t index = 0;
  for (char c = 'a'; c <= 'z'; c++)
  {
    bool present = false;
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
      if (std::isalpha(str[i]) && std::tolower(str[i]) == c)
      {
        present = true;
        break;
      }
    }
    if (!present)
    {
      missing[index++] = c;
    }
  }
  missing[index] = '\0';
}
