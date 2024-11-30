#include "tcab.h"

const char* hasExpr(const char* str);
const char* hasTerm(const char* str);
const char* hasMulti(const char* str);
const char* hasUInt(const char* str);
const char* hasIdent(const char* str);
const char* hasLetter(const char* str);
const char* hasNumber(const char* str);

bool demehin::isExpression(const char* str)
{
  auto next = hasExpr(str);
  if (!next)
  {
    return false;
  }
  return true;
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
    return str;
  }
  return hasLetter(str);
}

const char* hasUInt(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasNumber(str);
  if (next)
  {
    auto continues = hasUInt(next);
    if (continues)
    {
      return continues;
    }
  }
  return next;
}


const char* hasExpr(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasTerm(str);
  if (next)
  {
    if (*(next + 1) == '+' || *(next + 1) == '-')
    {
      next++;
      auto continues = hasExpr(next);
      if (continues)
      {
        return continues;
      }
    }
  }
  return next;
}

const char* hasMulti(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasUInt(str);
  if (next)
  {
    return next;
  }

  if (*str == '(')
  {
    str++;
    next = hasExpr(str);
    if (*next == ')')
    {
      return next;
    }
    return nullptr;
  }
  return nullptr;
}

const char* hasTerm(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasMulti(str);
  if (next)
  {
    if (*(next + 1) == '*')
    {
      next++;
      auto continues = hasTerm(next);
      if (continues)
      {
        return continues;
      }
    }
  }
  return next;
}









