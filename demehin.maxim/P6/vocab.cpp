#include "vocab.h"
const char* demehin::hasMultipl(const char* str)
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
  next = hasIdent(str);
  if (next)
  {
    return next;
  }
  next = hasExpr(str);
  return next;
}

const char* demehin::hasExpr(const char* str)
{
  if (!str)
  {
    return str;
  }
  if (*(str) == '(')
  {
    str++;
    if (auto next = demehin::isExpr(str))
    {
      if (*next == ')')
      {
        return next;
      }
    }
  }
  return nullptr;
}

const char* demehin::hasMultiplAndTerm(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = demehin::hasMultipl(str);
  if (next)
  {
    if (*(next++) == '*')
    {
      if (demehin::hasTerm(next))
      {
        return next;
      }
    }
  }
  return nullptr;
}

const char* demehin::hasTerm(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasMultipl(str);
  auto continues = demehin::hasMultiplAndTerm(next);
  if (continues)
  {
    return continues;
  }
  return next;
}

const char* demehin::hasTermPlusExpr(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasTerm(str);
  if (next)
  {
    if (*(next++) == '+')
    {
      if(isExpr(next))
      {
        return next;
      }
    }
  }
  return nullptr;
}

const char* demehin::hasTermMinusExpr(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasTerm(str);
  if (next)
  {
    if (*(next++) == '-')
    {
      if(isExpr(next))
      {
        return next;
      }
    }
  }
  return nullptr;
}

const char* demehin::isExpr(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = demehin::hasTerm(str);
  if (auto continues = demehin::hasTermPlusExpr(next))
  {
    return continues;
  }
  if (auto continues = demehin::hasTermMinusExpr(next))
  {
    return continues;
  }
  return next;
}


