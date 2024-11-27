#include "recursion.hpp"
#include <iostream>
const char * evstyunichev::IsFactorCorrect(const char *p, int prev)
{
  if (p == nullptr) return nullptr;
  int cur = 4;
  if (evstyunichev::IsLetter(*p))
  {
    cur = (prev == 3);
  }
  if (evstyunichev::IsDigit(*p))
  {
    cur = 2 & prev;
  }
  if (cur & 4)
  {
    return p;
  }
  if (cur)
  {
    return evstyunichev::IsFactorCorrect(++p, cur);
  }
  return nullptr;
}

const char * evstyunichev::IsTermCorrect(const char *p, int prev)
{
  if (p == nullptr)
  {
    return nullptr;
  }
  int cur = (p != IsFactorCorrect(p));
  if (cur)
  {
    return IsTermCorrect(IsFactorCorrect(p), 1);
  }
  if (!prev)
  {
    return nullptr;
  }
  if (*p != '*')
  {
    return p;
  }
  return IsTermCorrect(++p);
}

bool evstyunichev::IsLetter(char c)
{
  return (('a' <= c) && (c <= 'f') || ('x' <= c) && (c <= 'z'));
}

bool evstyunichev::IsDigit(char c)
{
  return (('0' <= c) && (c <= '9'));
}

bool evstyunichev::IsBasicSymbol(char c)
{
  return (evstyunichev::IsDigit(c) || evstyunichev::IsLetter(c));
}
