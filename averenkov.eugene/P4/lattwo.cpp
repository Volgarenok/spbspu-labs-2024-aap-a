#include "lattwo.h"
#include <memory>
#include <cstring>
#include <cctype>
#include <cstdlib>

void averenkov::latTwo(const char* str1, const char* str2, char* result)
{
  size_t n = 0;
  for (char ch = 'a'; ch <= 'z'; ++ch)
  {
    bool found = false;
    for (const char* p = str1; *p != '\0'; ++p)
    {
      if (std::isalpha(static_cast<unsigned char>(*p)) && std::tolower(static_cast<unsigned char>(*p)) == ch)
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      for (const char* p = str2; *p != '\0'; ++p)
      {
        if (std::isalpha(static_cast<unsigned char>(*p)) && std::tolower(static_cast<unsigned char>(*p)) == ch)
        {
          found = true;
          break;
        }
      }
    }
    if (found)
    {
      result[n++] = ch;
    }
  }
  result[n] = '\0';
}
