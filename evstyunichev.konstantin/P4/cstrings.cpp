#include "cstrings.hpp"

int evstyunichev::is_vowel(const char c)
{
  char good[] = {"aeiouyAEIOUY"};
  for (size_t i = 0; i < 12; i++)
  {
    if (c == good[i])
    {
      return 1;
    }
  }
  return 0;
}

size_t evstyunichev::cnt_not_vowel(const char *str)
{
  size_t ans = 0, i = 0;
  if (!str)
  {
    return ans;
  }
  while (str[i])
  {
    if (!is_vowel(str[i]))
    {
      ans++;
    }
    i++;
  }
  return ans;
}

int evstyunichev::rmv_vow(const char *str1, char *str2)
{
  if (!str2 || !str1)
  {
    return 0;
  }
  size_t i = 0, cur = 0;
  while (str1[i])
  {
    if (!is_vowel(str1[i]))
    {
      str2[cur] = str1[i];
      cur++;
    }
    i++;
  }
  str2[cur] = 0;
  return 1;
}
