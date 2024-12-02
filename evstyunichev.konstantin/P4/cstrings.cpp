#include "cstrings.hpp"
#include <iostream>
#include <ios>

constexpr size_t default_size = 256;

void evstyunichev::copy(char *str1, char *str2)
{
  if (!str1)
  {
    return;
  }
  for (size_t i = 0; str1[i] && str2[i]; i++)
  {
    str2[i] = str1[i];
  }
  return;
}

char * evstyunichev::resize_str(size_t sz, char *str)
{
  try
  {
    char *temp = new char[sz + 1];
    size_t i = 0;
    copy(str, temp);
    delete[] str;
    return temp;
  }
  catch(const std::bad_alloc &e)
  {
    return nullptr;
  }
}

char * evstyunichev::get_string(std::istream &in, char end)
{
  size_t sz = 0, mx = default_size;
  char *str = resize_str(mx);
  bool res = str;
  std::noskipws(in);
  char c = 0;
  while ((in >> c) && (c != end))
  {
    sz++;
    if(sz > mx)
    {
      mx *= 2;
      str = resize_str(mx, str);
    }
    str[sz - 1] = c;
  }
  return str;
}

int evstyunichev::is_vowel(char c)
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

size_t evstyunichev::cnt_not_vowel(char *str)
{
  size_t ans = 0, i = 0;
  while (str[i])
  {
    if (!is_vowel(str[i]))
    {
      ans++;
    }
    i++;
  }
  return ans + 1;
}

int evstyunichev::rmv_vow(char *str1, char *str2)
{
  if (!str2)
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

void evstyunichev::output(char *str, std::ostream &out)
{
  size_t i = 0;
  while (str[i])
  {
    out << str[i++];
  }
}

char * evstyunichev::create(size_t sz)
{
  char *str2 = nullptr;
  try
  {
    char *str2 = new char[sz + 1];
  }
  catch (const std::bad_alloc &e)
  {
    str2 = nullptr;
  }
  return str2;
}
