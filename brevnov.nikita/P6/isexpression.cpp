#include "isexpression.hpp"
namespace brevnov
{
  const char * isLetter(const char * str);
  const char * isDigit(const char * str);
  const char * hasUint(const char * str);
  const char * hasMultiplier(const char * str);
  const char * hasTerm(const char * str);
  const char * hasExpression(const char * str);
}

const char * brevnov::isLetter(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((*str == 'x') || (*str == 'y') || (*str == 'z')) ? (str + 1) : nullptr;
}

const char * brevnov::isDigit(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((*str == '1') || (*str == '0')) ? (str + 1) : nullptr;
}

const char * brevnov::hasUint(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = isDigit(str);
  if (next)
  {
    auto continues = hasUint(next);
    if (continues)
    {
      return continues;
    }
    else
    {
      return next;
    }
  }
  return next;
}

const char * brevnov::hasMultiplier(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (*str == '(')
  {
    str++;
    auto bracket = hasExpression(str);
    if (!bracket)
    {
      return bracket;
    }
    if (*bracket == ')')
    {
      return (bracket + 1);
    }
    else
    {
      return nullptr;
    }
  }
  auto next = hasUint(str);
  if (next)
  {
    return next;
  }
  return isLetter(str);
}

const char * brevnov::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasMultiplier(str);
  if (*str == '(')
  {
    str++;
    auto bracket = hasMultiplier(str);
    if (!bracket)
    {
      return nullptr;
    }
    if (*bracket == '+')
    {
      next = hasTerm(bracket + 1);
      if (!next)
      {
        return nullptr;
      }
      if (*next == ')')
      {
        next++;
      }
      else
      {
        return nullptr;
      }
    }
    else
    {
      return nullptr;
    }
  }
  if (!next)
  {
    return nullptr;
  }
  if (*next == '*')
  {
    next++;
    return hasTerm(next);
  }
  return next;
}

const char * brevnov::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasTerm(str);
  if (!next)
  {
    return next;
  }
  if (*next == '+' || *next == '-')
  {
    next++;
    return hasExpression(next);
  }
  return next;
}

bool brevnov::isExpression(const char * str)
{
  auto next = hasExpression(str);
  return next && (*next == '\0');
}
