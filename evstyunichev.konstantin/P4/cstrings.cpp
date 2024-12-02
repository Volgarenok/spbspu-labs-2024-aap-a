#include "cstrings.hpp"
#include <iostream>
#include <ios>

constexpr size_t default_size = 20;

void evstyunichev::copy(const char *str1, char *str2)
{
  if (!str1 || !str2)
  {
    return;
  }
  size_t i = 0;
  for (; str1[i]; i++)
  {
    str2[i] = str1[i];
  }
  return;
}

char * evstyunichev::resize_str(const size_t sz, const char *old)
{
  char *temp = nullptr;
  try
  {
    temp = new char[sz + 1];
    copy(old, temp);
    delete[] old;
  }
  catch(const std::bad_alloc &e)
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
    if(sz > mx)
    {
      char *temp = nullptr;
      mx *= 2;
      temp = resize_str(mx, str);
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
  return str;
}

int evstyunichev::is_vowel(const char c)
{
  char good[] = {"aeiouyAEIOUY"};
  int flag = 0;
  for (size_t i = 0; i < 6; i++)
  {
    if (c == good[i])
    {
      flag = 1;
    }
  }
  return flag;
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

void evstyunichev::output(const char *str, std::ostream &out)
{
  size_t i = 0;
  while (str[i])
  {
    out << str[i++];
  }
}
