#include "isExpression.hpp"
#include <iostream>

namespace
{
  const char * isSymbol(const char * str, const char c);
  const char * hasExpression(const char * str);
  const char * hasUnsignedInt(const char * str);
  const char * hasNumber(const char * str);
  const char * hasIdentifier(const char * str);
  const char * hasMultiplier(const char * str);
  const char * hasTerm(const char * str);
  const char * hasLetter(const char * str);

  const char * isSymbol(const char * str, const char c)
  {
    if (!str)
    {
      return str;
    }
    return (*str == c) ? (str + 1) : nullptr;
  }

  const char * hasExpression(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = hasTerm(str);
    if (!next)
    {
      return nullptr;
    }
    while (*next == '+' || *next == '-')
    {
      next = isSymbol(next, *next);
      next = hasTerm(next);
      if (!next)
      {
        return nullptr;
      }
    }
    return next;
  }

  const char * hasTerm(const char * str)
  {
    if (!str)
    {
      return str;
    }
    auto next = hasMultiplier(str);
    if (!next)
    {
      return nullptr;
    }
    while (*next == '*' || *next == '/')
    {
      next = isSymbol(next, *next);
      next = hasMultiplier(next);
      if (!next)
      {
        return nullptr;
      }
    }
    return next;
  }

  const char * hasMultiplier(const char * str)
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
    return nullptr;
  }

  const char * hasUnsignedInt(const char * str)
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

  const char * hasIdentifier(const char * str)
  {
    return hasLetter(str);
  }

  const char * hasNumber(const char * str)
  {
    if (!str)
    {
      return str;
    }
    return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
  }

  const char * hasLetter(const char * str)
  {
    if (!str)
    {
      return str;
    }
    return (*str >= 'a' && *str <= 'e') ? (str + 1) : nullptr;
  }
}

bool sharifullina::isExpression(const char * str)
{
  auto next = hasExpression(str);
  return next && (*next == '\0');
}
