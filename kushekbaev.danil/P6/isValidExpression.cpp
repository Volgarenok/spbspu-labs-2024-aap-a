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
  if (const char * continues = hasUnsignedInt(next))
  {
    return continues;
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
  next = hasExpression(next);
  next = hasCharacter(next, ')');
  return next;
}

const char * kushekbaev::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = hasMultiplier(str);
  if (const char * hchar_next = hasCharacter(next, '*'))
  {
    if (const char * continues = hasTerm(hchar_next))
    {
      return continues;
    }
  }
  return next;
}

const char * kushekbaev::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  const char * next = hasTerm(str);
  if (const char * next_plus = hasCharacter(next, '+'))
  {
    if (const char * continues = hasExpression(next_plus))
    {
      return continues;
    }
  }
  else if (const char * next_minus = hasCharacter(next, '-'))
  {
    if (const char * continues = hasExpression(next_minus))
    {
      return continues;
    }
  }
  return next;
}

bool kushekbaev::isValidExpression(const char * str)
{
  const char * next = hasExpression(str);
  return next && (*next == '\0');
}
