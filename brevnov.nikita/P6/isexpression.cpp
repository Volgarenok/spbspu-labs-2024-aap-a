#include "isexpression.hpp"
#include <iostream>

const char * classbrevnov::isLetter(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((*str == 'x') || (*str == 'y') || (*str == 'z')) ? (str + 1) : nullptr;
}

const char * classbrevnov::isDigit(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  return ((*str == '1') || (*str == '0')) ? (str + 1) : nullptr;
}

const char * classbrevnov::hasUint(const char * str)
{
  if (!str)
  {
    return nullptr;
  }
  auto next = classbrevnov::isDigit(str);
  if (next)
  {
    auto continues = classbrevnov::hasUint(next);
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

const char * classbrevnov::hasMultiplier(const char * str)
{
  if (!str)
  {
    return str;
  }
  if (*str == '(')
  {
    str++;
    auto bracket = classbrevnov::hasExpression(str);
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
  auto next = classbrevnov::hasUint(str);
  if (next)
  {
    return next;
  }
  return classbrevnov::isLetter(str);
}

const char * classbrevnov::hasTerm(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = classbrevnov::hasMultiplier(str);
  if (*str == '(')
  {
    str++;
    auto bracket = classbrevnov::hasMultiplier(str);
    if (!bracket)
    {
      return nullptr;
    }
    if (*bracket == '+')
    {
      next = classbrevnov::hasTerm(bracket + 1);
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
    return classbrevnov::hasTerm(next);
  }
  return next;
}

const char * classbrevnov::hasExpression(const char * str)
{
  if (!str)
  {
    return str;
  }
  auto next = classbrevnov::hasTerm(str);
  if (!next)
  {
    return next;
  }
  if (*next == '+' || *next == '-')
  {
    next++;
    return classbrevnov::hasExpression(next);
  }
  return next;
}

bool classbrevnov::isExpression(const char * str)
{
  auto next = classbrevnov::hasExpression(str);
  return next && (*next == '\0');
}
