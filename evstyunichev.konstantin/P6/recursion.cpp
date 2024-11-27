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
  if (IsBasicSymbol(*p))
  {
    return IsTermCorrect(IsFactorCorrect(p), 0);
  }
  if (*p == '(')
  {
    p++;
    p = IsExpressionCorrect(p, 1, 1);
    if (!p)
    {
      return p;
    }
    if (*p != ')')
    {
      return nullptr;
    }
    p++;
    return IsTermCorrect(p, 0);
  }
  if (prev)
  {
    return nullptr;
  }
  if (*p == '*')
  {
    return IsTermCorrect(++p);
  }
  return p;
}

const char * evstyunichev::IsExpressionCorrect(const char *p, int prev, bool OpenFlag)
{
  if (p == nullptr)
  {
    return nullptr;
  }
  if (IsBasicSymbol(*p))
  {
    return IsExpressionCorrect(IsTermCorrect(p), 0, OpenFlag);
  }
  if (*p == '(')
  {
    return IsTermCorrect(p);
  }
  if (prev)
  {
    return nullptr;
  }
  if (IsSign(*p))
  {
    return IsExpressionCorrect(++p, 1, OpenFlag);
  }
  if (*p == 0)
  {
    return p;
  }
  if (OpenFlag && (*p == ')'))
  {
    return p;
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

bool evstyunichev::IsBasicSymbol(char c)
{
  return (evstyunichev::IsDigit(c) || evstyunichev::IsLetter(c));
}

bool evstyunichev::IsSign(char c)
{
  return ((c == '+') || (c == '-'));
}
