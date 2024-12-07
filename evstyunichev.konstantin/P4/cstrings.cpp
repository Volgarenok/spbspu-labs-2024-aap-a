#include "cstrings.hpp"
#include <iostream>
#include <ios>

constexpr size_t default_size = 20;

size_t evstyunichev::copy(const char *str1, char *str2)
{
  size_t i = 0;
  if (!str1)
  {
    return i;
  }
  for (; str1[i] != '\0'; i++)
  {
    str2[i] = str1[i];
  }
  return i;
}

char * evstyunichev::resize_str(const size_t sz, const char *old)
{
  char *temp = nullptr;
  try
  {
    temp = new char[sz + 1];
    size_t cnt = copy(old, temp);
    temp[cnt] = 0;
    delete[] old;
  }
  catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  return temp;
}

char * evstyunichev::get_string(std::istream &in, const char end)
{
  size_t mx = default_size;
  char *str = resize_str(mx);
  if (!str)
  {
    return nullptr;
  }
  std::noskipws(in);
  char c = 0;
  size_t sz = 0;
  while ((in >> c) && (c != end))
  {
    sz++;
    if (sz > mx)
    {
      str[sz - 1] = 0;
      mx *= 2;
      char *temp = resize_str(mx, str);
      if (!temp)
      {
        delete[] str;
        return temp;
      }
      str = temp;
    }
    if (!str)
    {
      return str;
    }
    str[sz - 1] = c;
  }
  str[sz] = 0;
  return str;
}

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
