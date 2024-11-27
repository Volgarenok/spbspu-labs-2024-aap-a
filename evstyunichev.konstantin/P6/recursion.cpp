#include "recursion.hpp"

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

bool evstyunichev::IsLetter(char c)
{
  return (('a' <= c) && (c <= 'f') || ('x' <= c) && (c <= 'z'));
}

bool evstyunichev::IsDigit(char c)
{
  return (('0' <= c) && (c <= '9'));
}
