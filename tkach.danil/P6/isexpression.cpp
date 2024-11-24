#include "isexpression.h"
#include <cctype>
#include <cstddef>

bool tkach::isNeededSymbol(const char* symbol)
{
  return (*symbol >= 'a' && *symbol <= 'e');
}

bool tkach::isDigit(const char** str)
{
  if (std::isdigit(**str))
  {
    ++(*str);
    return true;
  }
  return false;
}

bool tkach::isSymbol(const char** str)
{
  if (isNeededSymbol(*str))
  {
    ++(*str);
    return true;
  }
  return false;
}

bool tkach::hasId(const char** str)
{
  return isSymbol(str);
}

bool tkach::hasNumber(const char** str)
{
  bool result = isDigit(str);
  if (result)
  {
    hasNumber(str);
  }
  return result;
}

bool tkach::hasMultiplier(const char** str)
{
  return hasNumber(str) || hasId(str);
}

bool tkach::hasTerm(const char** str)
{
  if (hasMultiplier(str))
  {
    if (**str == '*')
    {
      (*str)++;
      return hasTerm(str);
    }
    return true;
  }
  return false;
}

bool tkach::hasExpression(const char** str)
{
  if (hasTerm(str))
  {
    if ((**str == '+') || (**str == '-'))
    {
      (*str)++;
      return hasExpression(str);
    }
    return true;
  }
  return false;
}

bool tkach::isExpression(const char *str)
{
  return hasExpression(&str) && *str == '\0';
}
