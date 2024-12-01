#include "recfunc.h"

bool averenkov::hasDigit(char c)
{
  return c >= '0' && c <= '9';
}

bool averenkov::hasUnsignedInt(const char* str)
{
  const char* start = str;
  if (hasDigit(*str))
  {
    while (hasDigit(*str))
    {
      ++str;
    }
    return true;
  }
  str = start;
  return false;
}

bool averenkov::hasLetter(char c)
{
  return (c >= 'a' && c <= 'z');
}

bool averenkov::hasIdentifier(const char* str)
{
  if (hasLetter(*str))
  {
    ++str;
    return true;
  }
  return false;
}

bool averenkov::hasExpression(const char* str)
{
  const char* start = str;
  if (hasTerm(str)) {
    while (*str == '+' || *str == '-')
    {
      ++str;
      if (!hasTerm(str))
      {
        str = start;
        return false;
      }
    }
    return true;
  }
  return false;
}

bool averenkov::hasFactor(const char* str)
{
  const char* start = str;
  if (hasUnsignedInt(str))
  {
    return true;
  }
  str = start;
  if (hasIdentifier(str))
  {
    return true;
  }
  str = start;
  if (*str == '(')
  {
    ++str;
    if (hasExpression(str) && *str == ')')
    {
      ++str;
      return true;
    }
  }
  str = start;
  return false;
}

bool averenkov::hasTerm(const char* str)
{
  const char* start = str;
  if (hasFactor(str))
  {
    while (*str == '*' || *str == '/')
    {
      ++str;
      if (!hasFactor(str))
      {
        str = start;
        return false;
      }
    }
    return true;
  }
  return false;
}
