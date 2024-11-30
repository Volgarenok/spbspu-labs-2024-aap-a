#include "tcab.h"

const char* hasExpr(const char* str);
const char* hasTerm(const char* str);
const char* hasMulti(const char* str);
const char* hasUint(const char* str);
const char* hasIdent(const char* str);
const char* hasLetter(const char* str);
const char* hasNumber(const char* str);

bool demehin::isExpression(const char* str)
{
  auto next = hasExpr(str);
  return next && (*next == '\0');
}

const char* hasLetter(const char* str)
{
  if (!str)
  {
    return str;
  }

  bool isLetter = *str >= 'A' && *str <= 'E';
  return (isLetter) ? (str + 1) : nullptr;
}

const char* hasNumber(const char* str)
{
  if (!str)
  {
    return str;
  }

  bool isNumber = *str >= '0' && *str <= '9';
  return (isNumber) ? (str + 1) : nullptr;
}

const char* hasIdent(const char* str)
{
  if (!str)
  {
    return nullptr;
  }
  return hasLetter(str);
}

const char* hasUint(const char* str)
{
  if (!hasNumber(str))
  {
    return nullptr;
  }

  return hasUint(str + 1);
}


const char* hasExpr(const char* str)
{
  auto term = hasTerm(str);
  if (!term)
  {
    return term;
  }

  if (*term == '+' || *term == '-')
  {
    return hasExpr(term + 1);
  }
  return term;
}

const char* hasMulti(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasUint(str);
  if (next)
  {
    return next;
  }

  next = hasIdent(str);
  if (next)
  {
    return next;
  }

  if (*str == '(')
  {
    auto expr = hasExpr(str + 1);
    if (expr && *expr == ')')
    {
      return expr + 1;
    }
    return nullptr;
  }
  return nullptr;
}

const char* hasTerm(const char* str)
{
  auto mult = hasMulti(str);
  if (!mult)
  {
    return mult;
  }

  if (*mult == '*')
  {
    return hasTerm(mult + 1);
  }
  return mult;
}









