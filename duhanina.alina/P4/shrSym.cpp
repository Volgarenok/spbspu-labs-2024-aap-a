#include "functionStr.h"
#include <cctype>
#include <cstddef>

void duhanina::shrSym(const char* str, char*& result)
{
  bool isPresent[26] = {false};
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    if (std::isalpha(str[i]))
    {
      isPresent[std::tolower(str[i]) - 'a'] = true;
    }
  }
  size_t countMissing = 0;
  for (size_t i = 0; i < 26; ++i)
  {
    if (!isPresent[i])
    {
      ++countMissing;
    }
  }
  size_t index = 0;
  for (size_t i = 0; i < 26; ++i)
  {
    if (!isPresent[i])
    {
      result[index++] = 'a' + i;
    }
  }
  result[index] = '\0';
}
