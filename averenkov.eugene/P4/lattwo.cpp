#include "lattwo.h"
#include <cctype>
#include <cstddef>

bool hasChar(const char* str, char ch)
{
  for (const char* p = str; *p != '\0'; ++p)
  {
    if (std::isalpha(static_cast< unsigned char >(*p)) && std::tolower(static_cast< unsigned char >(*p)) == ch)
    {
      return true;
    }
  }
  return false;
}

void averenkov::latTwo(const char* str1, const char* str2, char* result)
{
  size_t n = 0;
  for (char ch = 'a'; ch <= 'z'; ++ch)
  {
    if (hasChar(str1, ch) || hasChar(str2, ch))
    {
      result[n++] = ch;
    }
  }
  result[n] = '\0';
}

