#include "string_processing.h"
#include <cctype>
#include <cstddef>
int bocharov::compare_symbols(const char * string1, const char * string2)
{
  for (const char * i = string1; *i != '\0'; ++i)
  {
    for (const char * j = string2; *j != '\0'; ++j)
    {
      if (*i == *j)
      {
        return 1;
      }
    }
  }
  return 0;
}

bool has_char(const char * string, char ch)
{
  for (const char * p = string; *p != '\0'; ++p)
  {
    if (std::isalpha(static_cast< unsigned char >(*p)) && std::tolower(static_cast< unsigned char >(*p)) == ch)
    {
      return true;
    }
  }
  return false;
}

void bocharov::merge_lines(const char * string1, const char * string2, char * result)
{
  size_t n = 0;
  for (char ch = 'a'; ch <= 'z'; ++ch)
  {
    if (has_char(string1, ch) || has_char(string2, ch))
    {
      result[n++] = ch;
    }
  }
  result[n] = '\0';
}
