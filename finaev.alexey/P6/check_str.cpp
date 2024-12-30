#include "check_str.h"
#include <cctype>

namespace finaev
{
  const char * isSymbol(const char * str, char a);
  const char * hasLetter(const char * str);
  const char * hasDigit(const char * str);
  const char * hasId(const char* str);
  const char * hasUnsignedInt(const char* str);
  const char * hasFactor(const char* str);
  const char * hasTerm(const char* str);
}

const char * finaev::isSymbol(const char * str, char a)
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
  return (std::isdigit(*str)) ? (str + 1) : nullptr;
}

const char * finaev::hasId(const char* str)
{
  return hasLetter(str);
}

const char * finaev::hasUnsignedInt(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasDigit(str);
  if (auto continues = hasUnsignedInt(next))
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
  auto next = hasUnsignedInt(str);
  if (next)
  {
    return next;
  }
  next = hasId(str);
  if (next)
  {
    return next;
  }
  next = isSymbol(str, '(');
  next = hasExpression(next);
  next = isSymbol(next, ')');
  return next;
}

const char * finaev::hasTerm(const char* str)
{
  if (!str)
  {
    return str;
  }
  auto next = hasFactor(str);
  if (auto continues = isSymbol(next, '*'))
  {
    continues = hasTerm(continues);
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
  auto next = hasTerm(str);
  if (auto continues = isSymbol(next, '+'))
  {
   continues = hasExpression(continues);
   return continues;
  }
  else if (auto continues = isSymbol(next, '-'))
  {
   continues = hasExpression(continues);
   return continues;
  }
  return next;
}

bool finaev::checkStr(const char * str)
{
  return (hasExpression(str) != nullptr);
}
