#include "recursionfunc.hpp"
#include <iostream>

namespace mozhegova
{
  const char * isSymbol(const char * str, const char c);
  const char * hasLetter(const char * str);
  const char * hasNumber(const char * str);
  const char * hasIdentifier(const char * str);
  const char * hasUnsignedInt(const char * str);
  const char * hasFactor(const char * str);
  const char * hasTerm(const char * str);
}

const char * mozhegova::isSymbol(const char * str, const char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

const char * mozhegova::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : nullptr;
}

const char * mozhegova::hasNumber(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
}

const char * mozhegova::hasIdentifier(const char * str)
{
  return hasLetter(str);
}

const char * mozhegova::hasUnsignedInt(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasNumber(str);
  if (auto continues = hasUnsignedInt(next))
  {
    return continues;
  }
  return next;
}

const char * mozhegova::hasFactor(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasUnsignedInt(str);
  if (next)
  {
    return next;
  }
  next = hasIdentifier(str);
  if (next)
  {
    return next;
  }
  next = isSymbol(str, '(');
  next = hasExpression(next);
  next = isSymbol(next, ')');
  return next;
}

const char * mozhegova::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasFactor(str);
  if (auto next2 = isSymbol(next, '*'))
  {
    if (auto continues = hasTerm(next2))
    {
      return continues;
    }
  }
  return next;
}

const char * mozhegova::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasTerm(str);
  if (auto next2 = isSymbol(next, '+'))
  {
    if (auto continues = hasExpression(next2))
    {
      return continues;
    }
  }
  else if (auto next2 = isSymbol(next, '-'))
  {
    if (auto continues = hasExpression(next2))
    {
      return continues;
    }
  }
  return next;
}

bool mozhegova::isExpression(const char * str)
{
  auto next = hasExpression(str);
  return next && (*next == '\0');
}
