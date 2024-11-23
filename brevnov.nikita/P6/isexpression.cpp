#include "isexpression.hpp"
#include <iostream>

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
  auto next = brevnov::isDigit(str);
  if (next)
  {
    auto continues = brevnov::hasUint(next);
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
    auto bracket = brevnov::hasExpression(str);
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
  auto next = brevnov::hasUint(str);
  if (next)
  {
    return next;
  }
  return brevnov::isLetter(str);
}

const char * brevnov::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = brevnov::hasMultiplier(str);
  if (*str == '(')
  {
    str++;
    auto bracket = brevnov::hasMultiplier(str);
    if (!bracket)
    {
      return nullptr;
    }
    if (*bracket == '+')
    {
      next = brevnov::hasTerm(bracket + 1);
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
    return brevnov::hasTerm(next);
  }
  return next;
}

const char * brevnov::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = brevnov::hasTerm(str);
  if (!next)
  {
    return next;
  }
  if (*next == '+' || *next == '-')
  {
    next++;
    return brevnov::hasExpression(next);
  }
  return next;
}

bool brevnov::isExpression(const char * str)
{
  auto next = brevnov::hasExpression(str);
  return next && (*next == '\0');
}
