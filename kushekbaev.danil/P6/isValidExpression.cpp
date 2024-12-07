#include "recursion.hpp"
#include <cctype>

namespace kushekbaev
{
  const char * hasCharacter(const char * str, char c);
  const char * hasLetter(const char * str);
  const char * hasNumber(const char * str);
  const char * hasUnsignedInt(const char * str);
  const char * hasMultiplier(const char * str);
  const char * hasTerm(const char * str);
  const char * hasExpression(const char * str);
}

const char * kushekbaev::hasCharacter(const char * str, char c)
{
  if (!str)
  {
    return str;
  }
  return (*str == c) ? (str + 1) : nullptr;
}

const char * kushekbaev::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : nullptr;
}

const char * kushekbaev::hasNumber(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
}

const char * kushekbaev::hasUnsignedInt(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = hasNumber(str);
  if (next)
  {
    while (const char * continues = hasNumber(next))
    {
      next = continues;
    }
  }
  return next;
}

const char * kushekbaev::hasMultiplier(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = hasUnsignedInt(str);
  if (next)
  {
    return next;
  }
  next = hasLetter(str);
  if (next)
  {
    return next;
  }
  next = hasCharacter(str, '(');
  if (next)
  {
    next = hasExpression(next);
    if (next)
    {
      next = hasCharacter(next, ')');
      return next;
    }
  }
  return nullptr;
}

const char * kushekbaev::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = hasMultiplier(str);
  if (next)
  {
    while (const char * hchar_next = hasCharacter(next, '*'))
    {
      next = hasMultiplier(hchar_next);
      if (!next)
      {
        return nullptr;
      }
    }
    return next;
  }
  return nullptr;
}

const char * kushekbaev::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = hasTerm(str);
  if (next)
  {
    while (const char * plus_next = hasCharacter(next, '+'))
    {
      next = hasTerm(plus_next);
      if (!next)
      {
        return nullptr;
      }
    }
    while (const char * minus_next = hasCharacter(next, '-'))
    {
      next = hasTerm(minus_next);
      if (!next)
      {
        return nullptr;
      }
    }
    return next;
  }
  return nullptr;
}

bool kushekbaev::isValidExpression(const char * str)
{
  const char * next = hasExpression(str);
  return next && (*next == '\0');
}
