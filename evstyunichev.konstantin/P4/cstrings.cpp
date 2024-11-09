#include "cstrings.hpp"
#include <iostream>
#include <ios>

constexpr size_t default_size = 256;

int evstyunichev::string_resize(char *s, size_t sz)
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


int evstyunichev::getstring(char *str, std::istream &in, char end)
{
  size_t sz = 0, mx = default_size;
  int res = 1;
  res = string_resize(str, mx);
  std::noskipws(in);
  unsigned char c = 0;
  while ((in >> c) && (c != end))
  {
    sz++;
    if(sz > mx)
    {
      mx *= 2;
      res = string_resize(str, mx);
    }
    str[sz - 1] = c;
  }
  return res;
}

int evstyunichev::isgl(char c)
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

void evstyunichev::RMV_VOW(char *str)
{
  size_t i = 0, cur = 0;
  while (str[i])
  {
    if (!isgl(str[i]))
    {
      str[cur] = str[i];
      cur++;
    }
    i++;
  }
  for (size_t j = cur; j < i; j++)
  {
    str[j] = 0;
  }
  return;
}

void evstyunichev::output(char *str, std::ostream &out)
{
  size_t i = 0;
  while (str[i])
  {
    out << str[i++];
  }
}
