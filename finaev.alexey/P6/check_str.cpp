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
  if (auto continues = finaev::hasUnsignedInt(str))
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
  next = finaev::hasExpression(str);
  next = finaev::isSymbol(str, ')');
  return next;
}

const char * finaev::hasTerm(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = finaev::hasFactor(str);
  if (auto continues = finaev::isSymbol(str, '*'))
  {
    continues = finaev::hasTerm(str);
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
  if (auto continues = finaev::isSymbol(str, '+'))
  {
   continues = finaev::hasExpression(str);
   return continues;
  }
  else if (auto continues = finaev::isSymbol(str, '-'))
  {
   continues = finaev::hasExpression(str);
   return continues;
  }
  return next;
}

bool finaev::checkStr(const char * str)
{
  return (hasExpression(str) != nullptr);
}
