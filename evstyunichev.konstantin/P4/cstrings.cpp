#include "cstrings.hpp"
#include <iostream>
#include <ios>

constexpr size_t default_size = 256;

int evstyunichev::StringResize(char *s, size_t sz)
{
  try
  {
    char *temp = new char[sz + 1];
    size_t i = 0;
    while (s[i])
    {
      temp[i] = s[i];
      i++;
    }
    delete[] s;
    s = temp;
    return 1;
  }
  catch(const std::bad_alloc& e)
  {
    return 0;
  }
}


int evstyunichev::GetString(char *str, std::istream &in, char end)
{
  size_t sz = 0, mx = default_size;
  int res = 1;
  res = StringResize(str, mx);
  std::noskipws(in);
  unsigned char c = 0;
  while ((in >> c) && (c != end))
  {
    sz++;
    if(sz > mx)
    {
      mx *= 2;
      res = StringResize(str, mx);
    }
    str[sz - 1] = c;
  }
  return res;
}

int evstyunichev::IsVowel(char c)
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

size_t evstyunichev::CntNotVowel(char *str)
{
  size_t ans = 0, i = 0;
  while (str[i])
  {
    if (!IsVowel(str[i]))
    {
      ans++;
    }
    i++;
  }
  return ans + 1;
}

void evstyunichev::RMV_VOW(char *str1, char *str2)
{
  size_t i = 0, cur = 0;
  while (str1[i])
  {
    if (!IsVowel(str1[i]))
    {
      str2[cur] = str1[i];
      cur++;
    }
    i++;
  }
  str2[cur] = 0;
  return;
}

void evstyunichev::Output(char *str, std::ostream &out)
{
  size_t i = 0;
  while (str[i])
  {
    out << str[i++];
  }
}

char * evstyunichev::Create(size_t sz)
{
  try
  {
    char *str2 = new char[sz + 1];
  }
  catch (std::bad_alloc() &e)
  {
    delete[] str2;
    str2 = nullptr;
  }
  return str2;
}
