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
  return (*str == c) ? (str + 1) : hasCharacter(str + 1, c);
}

const char * kushekbaev::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : hasLetter(str + 1);
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
  auto next = hasNumber(str);
  if (auto continues = hasUnsignedInt(next))
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
  auto next = hasUnsignedInt(str);
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
  auto next = hasMultiplier(str);
  if (auto hchar_next = hasCharacter(next, '*'))
  {
    if (auto continues = hasTerm(hchar_next))
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
  auto next = hasTerm(str);
  if (auto next_plus = hasCharacter(next, '+'))
  {
    if (auto continues = hasExpression(next_plus))
    {
      return continues;
    }
  }
  else if (auto next_minus = hasCharacter(next, '-'))
  {
    if (auto continues = hasExpression(next_minus))
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
