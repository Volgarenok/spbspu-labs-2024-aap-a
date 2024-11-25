#include "check_str.h"

const char * finaev::isSymbol(const char * str, const char a)
{
  if (!str)
  {
    return str;
  }
  return (*str == a) ? (str + 1) : nullptr;
}

const char * finaev::hasLetter(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= 'A' && *str <= 'E') ? (str + 1) : nullptr;
}

const char * finaev::hasDigit(const char * str)
{
  if (!str)
  {
    return str;
  }
  return (*str >= '0' && *str <= '9') ? (str + 1) : nullptr;
}

const char * finaev::hasId(const char* str)
{
  return finaev::hasLetter(str);
}

const char * finaev::hasUnsignedInt(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = finaev::hasDigit(str);
  if (auto continues = finaev::hasUnsignedInt(next))
  {
    return continues;
  }
  return next;
}

const char * finaev::hasFactor(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = finaev::hasUnsignedInt(str);
  if (next)
  {
    return next;
  }
  next = finaev::hasId(str);
  if (next)
  {
    return next;
  }
  next = finaev::isSymbol(str, '(');
  next = finaev::hasExpression(next);
  next = finaev::isSymbol(next, ')');
  return next;
}

const char * finaev::hasTerm(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = finaev::hasFactor(str);
  if (auto continues = finaev::isSymbol(next, '*'))
  {
    continues = finaev::hasTerm(continues);
    return continues;
  }
  return next;
}

const char * finaev::hasExpression(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = finaev::hasTerm(str);
  if (auto continues = finaev::isSymbol(next, '+'))
  {
   continues = finaev::hasExpression(continues);
   return continues;
  }
  else if (auto continues = finaev::isSymbol(next, '-'))
  {
   continues = finaev::hasExpression(continues);
   return continues;
  }
  return next;
}

bool finaev::checkStr(const char * str)
{
  return (finaev::hasExpression(str) != nullptr);
}
